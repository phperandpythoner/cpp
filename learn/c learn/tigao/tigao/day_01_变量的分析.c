/*
#include <stdio.h>

//变量的本质
//概述：变量是能写能读的内存对象，称为变量；能读不能写的称为常量

void main01()
{
	int a;
	char *p;

	//直接赋值
	a = 10;
	printf("a=%d\n", a);
	printf("&a = %d\n", &a);//&a = 11926428

	//间接赋值
	//*((int *)11926428) = 200;
	//printf("a2=%d\n", a);

	{
		p = &a;
		*p = 200;
	}
	printf("a=%d\n", a);

	printf("helle vs\n");
	system("pause");
}
*/