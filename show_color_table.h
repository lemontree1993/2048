#ifndef __SHOW_COLOR_TABLE_H__
#define __SHOW_COLOR_TABLE_H__

#include <stdio.h>

#define UNDO()		printf("\033[47;1m+----------+----------+----------+----------+\033[0m\n")
//#define VERTICAL()	printf("|          |          |          |          |\n")
#define p1 " "
#define p2 "  "
#define p3 "   "
#define p4 "    "
#define p5 "     "

#define VERTICAL()          printf("\033[47;1m|\033[0m")

#define SPACE()          printf("\033[46;1m          \033[0m")
#define RED1(val)        printf("\033[31;42;1m%6d%s\033[0m", val,p4)
#define GREEN1(val)      printf("\033[32;43;1m%6d%s\033[0m", val,p4)
#define YELLOW1(val)     printf("\033[33;44;1m%6d%s\033[0m", val,p4)
#define BLUE2(val)      printf("\033[34;45;1m%6d%s\033[0m", val,p4)
#define PURPLE2(val)    printf("\033[35;46;1m%6d%s\033[0m", val,p4)
#define DEEPGREEN2(val)  printf("\033[36;41;1m%6d%s\033[0m", val,p4)
#define GREEN3(val)    printf("\033[35;46;1m%6d%s\033[0m", val,p4)
#define YELLOW3(val)   printf("\033[34;45;1m%6d%s\033[0m", val,p4)
#define BLUE3(val)    printf("\033[33;44;1m%6d%s\033[0m", val,p4)
#define PURPLE4(val)  printf("\033[35;46;1m%6d%s\033[0m", val,p4)
#define DEEPGREEN4(val)  printf("\033[36;41;1m%6d%s\033[0m", val,p4)

//输出彩色数字
void print_number(int val);
//控制台显示地图
void c_show_table(int **map,int length);
#endif
