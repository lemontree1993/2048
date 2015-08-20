#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
//直接获取字符串
#include<termio.h>
#include"protocol.h"
#include"show_color_table.h"
#include"slide.h"
#include"game_initial.h"
#define length 4
#define QUIT 'q'
#define KEY_UP 27
#define KEY_DOWN ""
#define KEY_LEFT ""
#define KEY_RIGHT ""
struct Map
{
	int ** map;
};
//设置每三秒自动生成一个新数
void thread_set_new_num(struct Map * pmap);
char get_dir();
char screen_str(char *str);
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
	while((dir=get_dir())&& dir!=QUIT)
	{

		//吸收多余的字符串
//		while(getchar()!='\n');
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
	system("clear");
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
char get_dir()
{
	char str[4];
	int i;
	//设置缓冲区大小一个字符,即时读取字符消息
	struct termios new_settings;
	struct termios old_settings;
	//获得终端的设置
	tcgetattr(0,&old_settings);
	//修改设置
	new_settings = old_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	//再次获得新的设置
	tcgetattr(0,&old_settings);
	//设置自定义的属性
	tcsetattr(0,TCSANOW,&new_settings);
	for(i = 0; i < 3; i++)
	{
		str[i] = getchar();
		if((str[i] != UP) && (str[i] != DOWN) && (str[i] != LEFT) && (str[i] != RIGHT) && (str[i] != QUIT))
		{
			continue;
		}
		else
		{
			//使用结束,设置回原来的属性
			tcsetattr(0,TCSANOW,&old_settings);
			return str[i];
		}
	}
	//使用结束，设置回原来的属性
	tcsetattr(0,TCSANOW,&old_settings);
	return screen_str(str);
}
char screen_str(char* str)
{
	if(str[0] == 27)
	{
		if(str[1] == 91)
		{
			switch(str[2])
			{
				case 65:
					return UP;
				case 66:
					return DOWN;
				case 67:
					return RIGHT;
				case 68:
					return LEFT;
			}
		}
	}
	return 0;
}
