#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
//ָ�뺯��
//()���ȼ���*�ߣ����Ǻ���������ֵ��ָ�����͵ĺ���
int *fun()
{
	int *p = (int *)malloc(sizeof(int));

	return p;
}
*/



/*
����ָ��
int fun(int a)
{
	printf("a=================%d\n", a);
	return 0;
}

int main()
{
	//����ָ�룬����ָ�룬ָ������ָ��
	//���庯��ָ�������3�ַ���

	//1���ȶ��庯�����ͣ��ڸ������Ͷ���ָ������������ã�
	//��typedef�����ͣ�û�����Ǳ���
	typedef int FUN(int a);// FUN��������
	FUN *p1 = NULL;//����ָ�����
	p1 = fun;
	fun(10);
	p1(11);

	//2���ȶ��庯��ָ�����ͣ��������Ͷ���ָ����������ã�
	typedef int(*PFUN)(int a);
	PFUN p2 = fun;//p2ָ��fun
	p2(5);

	//3��ֱ�Ӷ��庯��ָ�루���ã�
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
//����ָ������
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
		printf("cmd��");
		scanf("%s", &cmd);

		for (i = 0; i < 5; i++)
		{
			if (strcmp(cmd, buf[i]) == 0)
			{
				fun[i]();
				break;//����forѭ��
			}
		}
	}
	printf("\n");

	system("pause");
	return 0;
}
*/



/*
//�ص�����
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