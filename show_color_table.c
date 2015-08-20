#include"show_color_table.h"
//输出长度相等的不同字符
void print_number(int val)
{
	switch(val)
	{
		case 0:
			SPACE();
			break;
		case 2:
			RED1(val);
			break;
		case 4:
			GREEN1(val);
			break;
		case 8:
			YELLOW1(val);
			break;
		case 16:
			BLUE2(val);
			break;
		case 32:
			PURPLE2(val);
			break;
		case 64:
			DEEPGREEN2(val);
			break;
		case 128:
			GREEN3(val);
			break;
		case 256:
			YELLOW3(val);
			break;
		case 512:
			BLUE3(val);
			break;
		case 1024:
			PURPLE4(val);
			break;
		case 2048:
			DEEPGREEN4(val);
			break;
	}
}


//控制台程序显示二维图
void c_show_table(int **map,int length)
{
	int raw,col;	
	printf("请输入'u','d','l','r'控制滑动\n");
	for(raw=0;raw<length;raw++)
	{
		UNDO();
	//	VERTICAL();
		for(col = 0; col < length; col++)
		{
			VERTICAL();
			SPACE();
		}
		VERTICAL();
		putchar('\n');
		for(col = 0; col < length; col++)
		{
			VERTICAL();
            print_number(*(*(map+raw)+col));
		}
		VERTICAL();
		putchar('\n');
		for(col = 0;col < length; col++)
		{
			VERTICAL();
            SPACE();
		}
		VERTICAL();
		putchar('\n');
	}
	UNDO();
}
//QT下显示二维图
