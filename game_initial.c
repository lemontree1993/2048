#include"game_initial.h"
#include"protocol.h"
#include"slide.h"
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int ** game_initial(int length)
{
	int **map;
	int i,j;
	map=malloc_map(length);
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			*(*(map+i)+j)=0;
		}
	}
	return map;
}
void game_over(int **map, int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        free(*(map+i));
    }
    free(map);
}
int is_over(int ** map,int length)
{
    int **tmp;
    int ok;
    tmp=game_initial(length);
    copy_map(tmp,map,length);
    slide_map(tmp,length,UP);
    slide_map(tmp,length,LEFT);
    ok=is_equal_map(tmp,map,length);
    game_over(tmp,length);
    return ok;
}
int is_over_btr(int ** map, int length)
{
	int i, j;
	for(i = 0; i < length; i++)
	{
		for(j = 0; j < length; j++)
		{
			if(has_same(map,i,j,length) || *(*(map+i)+j) == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
int has_same(int **map, int x, int y, int length)
{
	int i, j;
	for(i = -1; i <= 1; i++)
	{
		if((x+i) < 0 || (x+i) >= length)
		{
			continue;
		}
		for(j = -1; j <= 1; j++)
		{
			if(((y+j) < 0) || ((y+j) >= length) || (i == j || i == -j))
			{
				continue;
			}
			if(map[x][y] == map[x+i][y+j])
			{
				return 1;
			}
		}
	}
	return 0;
}
int * init_array(int * array,int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        *(array+i)=0;
    }
    return array;
}
int set_new_num(int **map, int length)
{
	//counts空位置数量,pos空单元格的位置,val新元素的大小
	int counts,pos,val;
	//存储counts个空单元格的位置
	int *array;

	counts=empty_unit_counts(map,length);
	if(counts == 0)
	{
		return 0;
	}
	array=(int*)malloc(counts*sizeof(int));

	empty_unit_pos_array(array,map,length);

	pos=random_num(0,counts-1);
//	val=convert_num(random_num(INI_NUM_MIN,INI_NUM_MAX));
	val=random_max(map_max_val(map,length));
	
	*(*(map+array[pos]/length)+array[pos]%length)=val;

	free(array);

	return 1;
}
int empty_unit_counts(int ** map,int length)
{
	int i,j,num=0;
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if(*(*(map+i)+j)==0)
			{
				num++;
			}
		}
	}
	return num;
}
int * empty_unit_pos_array(int * array,int **map,int length)
{
	int i,j,num=0;
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if(*(*(map+i)+j)==0)
			{
				*(array+num)=i*4+j;
				num++;
			}
		}
	}
	return array;
}
int random_num(int l_value,int r_value)
{
	srand((unsigned)time(NULL));
	return rand()%(r_value-l_value+1)+l_value;
}
int map_max_val(int ** map,int length)
{
	int i,j;
	int max=**map;
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
				max=max>*(*(map+i)+j)?max:(*(*map+i)+j);
		}
	}
	return max;
}
int random_max(int max)
{
	int rand_num;
	if(max>=1024)
		rand_num=3;
	else 
		rand_num = 2;
	srand(time(NULL));
	rand_num = 1 + (rand() % rand_num);
	rand_num = (int)pow(2,rand_num);
	return rand_num;
}
