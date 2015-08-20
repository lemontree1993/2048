#ifndef __GAME_INITIAL_H_
#define __GAME_INITIAL_H_
#define INI_NUM_MIN 1
#define INI_NUM_MAX 2

//功能：申请一个长度为length的二维数组，并赋初值0
int ** game_initial(int length);
//功能：判断2048地图是否能移动，不能则返回1，能则返回0
int is_over(int ** map,int length);
//功能：判断2048游戏是否结束加强版
int is_over_btr(int **map, int length);
//功能：游戏结束时调用，释放申请的二维数组空间
void game_over(int **map,int length);
//功能：游戏所使用的map生成新元素
int set_new_num(int ** map, int length);


//判断周围相连的元素是否有相同的元素
int has_same(int **map, int x, int y, int length);
//初始化一维数组
int * init_array(int *array,int length);
//找出图中为空的单元的个数
int empty_unit_counts(int ** map,int length);
//将图中为空的单元的位置存入数组
int * empty_unit_pos_array(int *array,int **map,int length);
//获得一个在区间内的随机整数
int random_num(int l_value,int r_value);
//获得图中的最大值
int map_max_val(int ** map,int length);
//新元素生成随最大值变化而变化
int random_max(int max);

#endif
