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

/*
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
*/




/*指针数组*/

/*
//二级指针做输出：第一种内存模型
int main01()
{
	int i, j;
	char *tmp;
	char *p[] = { "22222", "11111", "ccccc", "aaaaa" };
	int n = sizeof(p) / sizeof(p[0]);
	printf("排序之前\n");
	for (i = 0; i < n; i++)
	{
		//printf("%s\n", p[i]);
		printf("%s\n", *(p+i));
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (p[j] > p[j+1])
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	printf("排序后\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n",p[i]);
	}

	system("pause");
	return 0;
}


//通过封装函数方式输出
//void print_array(char *p[], int n)
void print_array(char **p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		//printf("%s\n", p[i]);
		printf("%s\n", *(p + i));
	}
	return;
}
//void sort_array(char *p[], int n)
void sort_array(char **p, int n)
{
	int i, j;
	char *tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (p[j] > p[j + 1])
			{
				tmp = p[j]; // tmp = *(p+j)
				p[j] = p[j + 1]; // *(p+j) = *(p+j+1);
				p[j + 1] = tmp; // *(p+j+1) = tmp;
			}
		}
	}
	
	return;
}
int main()
{
	char *p[] = { "22222", "11111", "ccccc", "aaaaa" };
	int n = sizeof(p) / sizeof(p[0]);
	printf("排序之前\n");
	print_array(p, n);
	printf("排序后\n");
	sort_array(p, n);
	print_array(p, n);

	system("pause");
	return 0;
}
*/


/*
//二级指针做输出：第二种内存模型
int main01()
{
	//4个a[30]的一维数组，二维数组
	//定义二维数组，不写第一个[]值是有条件，必须初始化
	//a代表首行地址，首行地址和首行首元素地址是有区别，但是他们的值是一样
	//区别：步长不一样
	//char a[4][30] = { "22222", "11111", "ccccc", "aaaaa" };
	char a[][30] = { "22222", "11111", "ccccc", "aaaaa" };
	char b[30];
	int i = 0;
	
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("&a=%d,&a+1=%d\n", a, a+1); //&a=6158776,&a+1=6158806
	printf("&b=%d,&b+1=%d\n", b, b+1); //&b=6158736,&b+1=6158737

	for (i = 0; i < 4; i++)
	{
		printf("%s\n", a[i]);
	}

	system("pause");
	return 0;
}


//函数封装
void print_array(char a[][30], int n)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", a[i]);
	}

	return;
}
void sort_array(char a[][30], int n)
{
	int i, j;
	char tmp[30];
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(a[i], a[j]) > 0)
			{
				strcpy(tmp, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], tmp);
			}
		}
	}
	
	return;
}
int main()
{
	char a[][30] = { "22222", "11111", "ccccc", "aaaaa" };
	int n = sizeof(a) / sizeof(a[0]);
	printf("before sort\n");
	print_array(a, n);
	printf("\nafter sort\n");
	sort_array(a, n);
	print_array(a, n);

	system("pause");
	return 0;
}
*/


/*
//二级指针做输出：第三种内存模型
int main01()
{
	int a[10];
	int n = 10;
	int i;
	int *p = (int *)malloc(n * sizeof(int)); // p[10]
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(p)=%d\n\n", sizeof(p));

	//动态分配
	char **buf = (char **)malloc(n * sizeof(char *));// char *buf[10]
	printf("sizeof(buf)=%d\n", sizeof(buf));
	if (buf == NULL)
	{
		return -1;
	}
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
		char str[30];
		sprintf(str, "test%d", i);
		strcpy(buf[i], str);
	}
	for (i = 0; i < n; i++)
	{
		printf("%s,", buf[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (buf[i] != NULL)
		{
			free(buf[i]);
			buf[i] = NULL;
		}
	}
	if (buf != NULL)
	{
		free(buf);
	}

	system("pause");
	return 0;
}


//函数封装
char **getMen(int n)
{
	int i = 0;
	//动态分配
	char **buf = (char **)malloc(n * sizeof(char *));
	printf("sizeof(buf)=%d\n", sizeof(buf));
	if (buf == NULL)
	{
		return NULL;
	}
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
		char str[30];
		sprintf(str, "test%d", i);
		strcpy(buf[i], str);
	}
	
	return buf;
}
void print_buf(char **buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s,",buf[i]);
	}
	printf("\n");
}
void free_buf(char **buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		//释放堆区buf[i]
		if (buf[i] != NULL)
		{
			free(buf[i]);
			buf[i] = NULL;
		}
	}

	//这个释放栈区局部变量buf
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}
int main01()
{
	char **buf = NULL;
	int n = 3;
	buf = getMen(n);
	if (buf == NULL)
	{
		printf("getMen() err\n");
		return -1;
	}

	print_buf(buf, n);

	free_buf(buf, n);
	if (buf != NULL)
	{
		printf("main里面的buf还没有释放！\n");
	}
	buf = NULL;

	system("pause");
	return 0;
}
*/

/*
//指针数组
int main(int argc, char *argv[])
{
	//指针数组，它是数组，每个元素都是指针
	//[]比*优先级高
	char *a[] = { "aaa", "bbb", "ccc" };

	int i = 0;
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	printf("agrc=%d\n", argc);

	system("pause");
	return 0;
}
*/

/*
//数组指针:定义方法1
int main()
{
	int a[10] = { 0 };
	int i = 0;

	//1、先定义数组类型，根据类型定义指针变量
	typedef int A[10]; //A数组类型，[10]代表步长
	A *p = NULL; //p数组类型变量
	//p = a; //a代表首元素地址， a与&a一样，最终也当作&a，但在编译会有警告
	p = &a; // 整个数组首地址

	for (i = 0; i < 10; i++)
	{
		(*p)[i] = i + 1; // 给数组类型变量赋值
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*p)[i]);
	}

	system("pause");
	return 0;
}
*/

/*
//数组指针:定义方法2
int main()
{
	int a[10] = { 0 };
	int i = 0;

	//2、先定义数组指针类型，根据类型定义指针变量
	//() 与 []优先级一样，从左往右
	typedef int(*P)[10];
	P q;//数组指针变量
	q = &a;

	for (i = 0; i < 10; i++)
	{
		(*q)[i] = 2*i + 1; // 给数组类型变量赋值
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*q)[i]);
	}

	system("pause");
	return 0;
}
*/