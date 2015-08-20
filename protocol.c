#include "protocol.h"
#include "math.h"
#include"stdlib.h"
int ** copy_map(int ** new_map,int ** map,int length)
{
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
            *(*(new_map+i)+j)=*(*(map+i)+j);
        }
    }
    return new_map;
}
int is_equal_map(int ** map1,int **map2,int length)
{
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
            if(*(*(map1+i)+j)!=*(*(map2+i)+j))
            {
                return 0;
            }
        }
    }
    return 1;
}
int ** malloc_map(int length)
{
	int i;
	int ** map;
	map=(int**)malloc(length*sizeof(int*));
	for(i=0;i<length;i++)
	{
		*(map+i)=(int*)malloc(length*sizeof(int));
	}
	return map;
}

int convert_num(int val)
{
	return (int)pow(2,val);
}

void exc(int *a,int* b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
