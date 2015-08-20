#include"protocol.h"
#include"show_color_table.h"
#include"slide.h"
#include"game_initial.h"
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#define length 4
struct Map
{
	int ** map;
};
void thread_set_new_num(struct Map * pmap);

int main()
{

	/*****************************************多线程编程*******************************************/
	//方向
	int dir;
	//创建地图
	int **map;
	int **tmp;
	struct Map pmap;
	//创建线程id和线程返回值ret
	int ret;
	pthread_t tid;
	//初始化地图
	tmp=game_initial(length);
	map=game_initial(length);
	pmap.map = map;
	//设置新元素,产生2，4，8
	set_new_num(map,length);
	//创建线程
	ret = pthread_create(&tid,NULL,(void*)thread_set_new_num,(void*)&pmap);
	if(ret != 0)
	{
		printf("创建线程失败\n");
		exit(0);
	}
	system("clear");
	c_show_table(map,length);
	//循环，一直获得输入的方向dir
	while((dir=getchar())&& dir!='q')
	{
		//吸收多余的字符串
		while(getchar()!='\n');
		//复制地图
		copy_map(tmp,map,length);
		//滑动地图
		slide_map(map,length,dir);
		//判断地图是否相等,相等说明地图没有变化,再次获取方向否则继续生成新的元素
		if(is_equal_map(map,tmp,length))
		{
			system("clear");
			c_show_table(map,length);
			continue;
		}
		//生成新元素
		set_new_num(map,length);
		//判断游戏是否结束,否则继续运行
		if(is_over_btr(map,length))
		{
			break;
		}
		system("clear");
		c_show_table(map,length);
	}
	//释放游戏资源
	c_show_table(map,length);
	printf("游戏结束");
	game_over(map,length);
	game_over(tmp,length);
}

void thread_set_new_num(struct Map * pmap)
{
	while(empty_unit_counts(pmap->map,length))
	{	
		set_new_num(pmap->map,length);
		system("clear");
		c_show_table(pmap->map,length);
		sleep(3);
	}
	system("clear");
	c_show_table(pmap->map,length);
	printf("game over\n");
	exit(0);
}

