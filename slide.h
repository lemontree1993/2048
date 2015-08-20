#ifndef __SLIDE_H_
#define __SLIDE_H_
#include"protocol.h"
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'


//整张地图的滑动,最后一个参数为方向
int** slide_map(int ** map,int length,char dir);



//二维数组的上下滑动
int ** UDN_slide(int ** map,int length,char dir);
//二维数组的左右滑动
int ** LRN_slide(int **map,int length,char dir);
//二维数组的对称转换
int ** convert_map(int ** map,int length);
//2048规则下：一维数组的左右滑动
int * LR_slide(int * array,int length,char dir);
//2048规则下：合并一维数组算法1
//int * slide_array1(int * array,int length);
//2048规则下：合并一维数组算法2
int * slide_array(int * array,int length);
//一维数组左右对调
int * LR_exc(int * array,int length);
//2048贵族下：合并一维数组算法3，将数组合并,前提是已将无关的数（0）移到后面
int * unifier_array(int * array,int length,int num);
//将数组中的所有的无关数排（0）到第一个位置
int * bubble_all_num(int *array,int length,int num);
//冒泡,将数组中末尾的无关数（0）排到第一
int * bubble_num(int *array,int length,int num);

#endif
