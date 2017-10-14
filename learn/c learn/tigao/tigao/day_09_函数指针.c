#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
//指针函数
//()优先级比*高，它是函数，返回值是指针类型的函数
int *fun()
{
	int *p = (int *)malloc(sizeof(int));

	return p;
}
*/



/*
函数指针
int fun(int a)
{
	printf("a=================%d\n", a);
	return 0;
}

int main()
{
	//函数指针，它是指针，指向函数的指针
	//定义函数指针变量有3种方法

	//1、先定义函数类型，在根据类型定义指针变量（不常用）
	//有typedef是类型，没有则是变量
	typedef int FUN(int a);// FUN函数类型
	FUN *p1 = NULL;//函数指针变量
	p1 = fun;
	fun(10);
	p1(11);

	//2、先定义函数指针类型，根据类型定义指针变量（常用）
	typedef int(*PFUN)(int a);
	PFUN p2 = fun;//p2指向fun
	p2(5);

	//3、直接定义函数指针（常用）
	int(*p3)(int a) = fun;
	p3(6);

	int(*p4)(int a);
	p4 = fun;
	p4(7);

	system("pause");
	return 0;
}
*/



/*
//函数指针数组
void add()
{
	printf("add==========================\n");
	return;
}
void minus()
{
	printf("minus==========================\n");
	return;
}
void multiply()
{
	printf("multiply==========================\n");
	return;
}
void divide()
{
	printf("divide==========================\n");
	return;
}
void myexit()
{
	exit(0);
}

int main()
{
	void(*fun[5])() = { add, minus, multiply, divide, myexit };
	char *buf[] = { "add", "minus", "multiply", "divide", "myexit" };
	int i = 0;
	char cmd[100];

	while (1)
	{
		printf("cmd：");
		scanf("%s", &cmd);

		for (i = 0; i < 5; i++)
		{
			if (strcmp(cmd, buf[i]) == 0)
			{
				fun[i]();
				break;//跳出for循环
			}
		}
	}
	printf("\n");

	system("pause");
	return 0;
}
*/



/*
//回调函数
void add(int a, int b)
{
	return a + b;
}
void minus(int a, int b)
{
	return a - b;
}

void fun(int x, int y, int(*p)(int a, int b))
{
	int a = p(x, y);
	printf("%d\n", a);
}

typedef int(*Q)(int a, int b);
void fun2(int x, int y, Q p)
{
	int a = p(x, y);
	printf("%d\n", a);
}

int main()
{
	//fun(2, 3, add);
	//fun(10, 2, minus);

	fun2(11, 2, add);
	fun2(33, 19, minus);

	system("pause");
	return 0;
}
*/