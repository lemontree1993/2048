#ifndef __PROTOCOL_H_
#define __PROTOCOL_H_

#define ZERO 0


//判断两个尺寸大小相同的二维数组内容是否完全相等，是则返回1，否则返回0
int is_equal_map(int ** map1,int **map2,int length);
//将二维数组的内容复制到新的二维数组中，并返回新数组的指针
int ** copy_map(int ** new_map,int ** map,int length);
//申请一个长度为length的二维数组
int ** malloc_map(int length);
//将0,1,2,3,4,5,6转换为2,4,8...并返回转换值
int convert_num(int val);
//交换a，b内容
void exc(int * a,int * b);


#endif
