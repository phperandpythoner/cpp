#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
char * fun3()
{
	char *p = NULL;
	p = "abcd";
	printf("&p=%x\n", &p);
	printf("*p=%p\n", *p);

	return p;
}

char * fun4()
{
	char *a = NULL;
	a = "abcd";
	printf("&a=%x\n", &a);
	printf("*a=%p\n", *a);

	return a;
}

void main()
{
	//printf("fun3()=%s\n", fun3());

	char *p = fun3();
	char *a = fun4();
	//&p = 12ffaf0
	//&a = 12ffaf0

	printf("123\n");
	system("pause");
	return;
}
*/

/*
//间接赋值
//通过函数间接赋值，参数为二级指针
void fun5(char **p)
{
	*p = 300;
}

void main()
{
	char *p1 = NULL;
	char **p2 = NULL;

	p1 = 100;
	p2 = &p1;
	*p2 = 200; //间接赋值
	printf("p1=%d\n", p1);//200

	//把p1的地址作为参数，fun5()里*p=300指向p1所指向的内存空间赋值
	fun5(&p1);
	printf("p1=%d\n", p1);//300

	system("pause");
	return;
}
*/

/*
int changemem(char **p1, int *len1, char **p2, int *len2)
{
	int ret = 0;
	char *tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "abcd");

	*len1 = strlen(tmp1);//1级间接赋值，指向参数len1地址所指向的内存空间
	*p1 = tmp1; //2级间接赋值

	tmp2 = (char *)malloc(100); //3、形参间接去修改实参的值
	strcpy(tmp2, "aaasssddd"); //3、形参间接去修改实参的值

	*len2 = strlen(tmp2);//1级间接赋值，指向参数len2地址所指向的内存空间
	*p2 = tmp2;//2级间接赋值

	return ret;
}

//间接赋值成立的三个条件
//1、定义一个变量，实参；定义一个变量，形参
//2、建立关联，把实参取地址传给形参
//3、形参间接去修改实参的值

int main()
{
	int ret = 0;
	char *p1 = NULL; //1、定义一个变量，实参；定义一个变量，形参
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	ret = changemem(&p1, &len1, &p2, &len2); //2、建立关联，把实参取地址传给形参
	if (ret != 0)
	{
		perror("function changemem() err");
		return 0;
	}

	printf("p1=%s, len1=%d\np2=%s, len2=%d\n", p1, len1, p2, len2);

	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	system("pause");
	return 0;
}
*/

/*
int *fun()
{
	static int a = 10;
	return &a;
}

int main()
{
	int *p = NULL;
	p = fun();//执行函数后静态局部变量没有释放，还可以操作指针所指向的内存
	printf("p=%d\n", *p);
	*p = 20;
	printf("p2=%d\n", *p);

	system("pause");
	return 0;
}
*/

int getstr(char *source, char *buf1, char *buf2)
{
	int ret = 0;
	int n = strlen(source);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if ((i % 2) != 0)
		{
			*buf1 = source[i];
			buf1++;
		}
		else
		{
			*buf2 = *(source + i);
			buf2++;
		}
	}

	//加结束符
	*buf1 = 0;
	*buf2 = 0;

	return ret;
}
//把字符串"1a2b3c4d5e"按奇、偶数分离
int main()
{
	char *p = "1a2b3c4d5e";
	char buf1[50];
	char buf2[50];
	int ret = 0;

	ret = getstr(p, buf1, buf2);
	if (ret != 0)
	{
		printf("getstr function err:%d\n", ret);
		return -1;
	}

	printf("buf1=%s\nbuf2=%s\n", buf1, buf2);
	
	system("pause");
	return 0;
}