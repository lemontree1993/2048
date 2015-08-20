#include"protocol.h"
#include"show_color_table.h"
#include"slide.h"
#include"game_initial.h"
#include<stdio.h>
#define length 4

int main()
{
	//方向
	int dir;
	//创建地图
	int **map;
	int **tmp;
	//初始化地图
	tmp=game_initial(length);
	map=game_initial(length);
	//设置新元素,产生2，4，8
	set_new_num(map,length);
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
			//释放游戏资源
			c_show_table(map,length);
			printf("游戏结束");
			game_over(map,length);
			game_over(tmp,length);
			break;
		}
		system("clear");
		c_show_table(map,length);
	}
}
