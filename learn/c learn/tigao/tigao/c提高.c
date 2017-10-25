#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include "memwatch.h"

/*
//选择法排序
int main()
{
	char a[] = {6,2,4,9,4,5,8,7,1,0,10};
	char tmp;
	int i, j;
	int n = sizeof(a) / sizeof(a[0]);
	printf("before\n");
	for (i = 0; i < n; i++)
	{
		printf("%d,", a[i]);
	}
	printf("\nafter\n");
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d,", a[i]);
	}

	system("pause");
	return 0;
}
*/



/*
//函数递归
int add(int n)
{
	if (n == 100)
	{
		return n;
	}

	return n + add(n + 1);
}

int add2(int n)
{
	if (n == 1)
	{
		return n;
	}

	return n + add2(n - 1);
}

int main()
{
	//累加1-100的结果
	int i = 0;
	int sum = 0;
	for (i = 0; i <= 100; i++)
	{
		sum += i;
	}
	printf("累加1-100的结果：%d\n", sum);


	printf("函数递归累加1-100的结果：%d\n", add(1));


	printf("函数递归累加1-100的结果：%d\n", add2(100));

	system("pause");
	return 0;
}
*/



/*
//内存检测
int main()
{
	char *p = (char *)malloc(100);

	system("pause");
	return 0;
}
*/