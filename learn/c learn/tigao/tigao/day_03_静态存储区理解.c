/*
#include <stdio.h>

//指针指向谁，就把谁的地址赋值给指针
//指针变量 和 他所指向的内存空间变量是两个不同的概念

char * fun1()
{
	char *p1 = "abc";
	return p1;
}

char * fun2()
{
	char *p2 = "abc";
	return p2;
}

void main03()
{
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = fun1();
	p2 = fun2();

	//打印的是p1,p2在内存空间的数据
	printf("p1=%s, p2=%s\n", p1, p2);
	//p1=abc, p2=abc
	
	//打印p1,p2的值
	printf("p1=%d, p2=%d\n", p1, p2);
	//p1=10582872, p2=10582872
	
	system("pause");
}
*/