#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
int main()
{
	int a[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	// a	代表第0行首地址
	// a+i -> &a[i] 代表第i行首地址
	// *(a+i) -> a[i] 代表第i行首元素地址
	// *(a+i)+j -> &a[i][j] 代表第i行第j列元素的地址
	// *(*(a+i)+j) -> a[i][j] 代表第i行第j列的值

	printf("a:%d, a+1:%d\n", a, a+1);
	// a:10288060, a+1:10288076
	printf("a:%d, *(a+1):%d, *(a+2):%d\n", a, *(a+1), *(a+2));
	//a:14483144, *(a+1):14483160, *(a+2):14483176
	printf("*a:%d, *a+1:%d, *a+2:%d\n", *a, *a+1, *a+2);
	//*a:16317636, *a + 1 : 16317640, *a + 2 : 16317644
	printf("&a[0][0]:%d, &a[0][1]:%d, &a[0][2]:%d\n", &a[0][0], &a[0][1], &a[0][2]);
	//&a[0][0] : 16317636, &a[0][1] : 16317640, &a[0][2] : 16317644


	int i, j,col_num,row_num;
	row_num = sizeof(a) / sizeof(a[0]); 
	col_num = sizeof(a[0]) / sizeof(int); // sizeof(a[0])/sizeof(a[0][0])
	printf("row_num:%d, col_num:%d\n", row_num, col_num);
	for (i = 0; i < row_num; i++)
	{
		for (j = 0; j < col_num; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	system("pause");
	return 0;
}
*/

/*
//void printArray(int a[3][4], int row_num, int col_num)//初级用法
//void printArray(int a[][4], int row_num, int col_num) //中级用法
void printArray(int (*a)[4], int row_num, int col_num) //高级用法
{
	int i, j;
	for (i = 0; i < row_num; i++)
	{
		for (j = 0; j < col_num; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}

int main()
{
	int a[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int row_num = sizeof(a) / sizeof(a[0]);
	int col_num = sizeof(a[0]) / sizeof(int); // sizeof(a[0])/sizeof(a[0][0])
	printArray(a, row_num, col_num);

	system("pause");
	return 0;
}
*/

/*
//数组指针和二维数组
int main()
{
	int a[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int (*p)[4];
	p = a; //第0行首地址

	printf("p:%d, p+1:%d\n", p, p+1);
	int row_num = sizeof(a) / sizeof(a[0]);
	int col_num = sizeof(a[0]) / sizeof(int); // sizeof(a[0])/sizeof(a[0][0])
	int i, j;
	for (i = 0; i < row_num; i++)
	{
		for (j = 0; j < col_num; j++)
		{
			//printf("%d ", p[i][j]);
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
	printf("\n");

	system("pause");
	return 0;
}
*/