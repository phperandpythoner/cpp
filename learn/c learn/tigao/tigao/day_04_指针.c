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
//��Ӹ�ֵ
//ͨ��������Ӹ�ֵ������Ϊ����ָ��
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
	*p2 = 200; //��Ӹ�ֵ
	printf("p1=%d\n", p1);//200

	//��p1�ĵ�ַ��Ϊ������fun5()��*p=300ָ��p1��ָ����ڴ�ռ丳ֵ
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

	*len1 = strlen(tmp1);//1����Ӹ�ֵ��ָ�����len1��ַ��ָ����ڴ�ռ�
	*p1 = tmp1; //2����Ӹ�ֵ

	tmp2 = (char *)malloc(100); //3���βμ��ȥ�޸�ʵ�ε�ֵ
	strcpy(tmp2, "aaasssddd"); //3���βμ��ȥ�޸�ʵ�ε�ֵ

	*len2 = strlen(tmp2);//1����Ӹ�ֵ��ָ�����len2��ַ��ָ����ڴ�ռ�
	*p2 = tmp2;//2����Ӹ�ֵ

	return ret;
}

//��Ӹ�ֵ��������������
//1������һ��������ʵ�Σ�����һ���������β�
//2��������������ʵ��ȡ��ַ�����β�
//3���βμ��ȥ�޸�ʵ�ε�ֵ

int main()
{
	int ret = 0;
	char *p1 = NULL; //1������һ��������ʵ�Σ�����һ���������β�
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	ret = changemem(&p1, &len1, &p2, &len2); //2��������������ʵ��ȡ��ַ�����β�
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
	p = fun();//ִ�к�����̬�ֲ�����û���ͷţ������Բ���ָ����ָ����ڴ�
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

	//�ӽ�����
	*buf1 = 0;
	*buf2 = 0;

	return ret;
}
//���ַ���"1a2b3c4d5e"���桢ż������
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




/*ָ������*/

/*
//����ָ�����������һ���ڴ�ģ��
int main01()
{
	int i, j;
	char *tmp;
	char *p[] = { "22222", "11111", "ccccc", "aaaaa" };
	int n = sizeof(p) / sizeof(p[0]);
	printf("����֮ǰ\n");
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

	printf("�����\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n",p[i]);
	}

	system("pause");
	return 0;
}


//ͨ����װ������ʽ���
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
	printf("����֮ǰ\n");
	print_array(p, n);
	printf("�����\n");
	sort_array(p, n);
	print_array(p, n);

	system("pause");
	return 0;
}
*/


/*
//����ָ����������ڶ����ڴ�ģ��
int main01()
{
	//4��a[30]��һά���飬��ά����
	//�����ά���飬��д��һ��[]ֵ���������������ʼ��
	//a�������е�ַ�����е�ַ��������Ԫ�ص�ַ�������𣬵������ǵ�ֵ��һ��
	//���𣺲�����һ��
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


//������װ
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
//����ָ����������������ڴ�ģ��
int main01()
{
	int a[10];
	int n = 10;
	int i;
	int *p = (int *)malloc(n * sizeof(int)); // p[10]
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(p)=%d\n\n", sizeof(p));

	//��̬����
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


//������װ
char **getMen(int n)
{
	int i = 0;
	//��̬����
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
		//�ͷŶ���buf[i]
		if (buf[i] != NULL)
		{
			free(buf[i]);
			buf[i] = NULL;
		}
	}

	//����ͷ�ջ���ֲ�����buf
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
		printf("main�����buf��û���ͷţ�\n");
	}
	buf = NULL;

	system("pause");
	return 0;
}
*/

/*
//ָ������
int main(int argc, char *argv[])
{
	//ָ�����飬�������飬ÿ��Ԫ�ض���ָ��
	//[]��*���ȼ���
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
//����ָ��:���巽��1
int main()
{
	int a[10] = { 0 };
	int i = 0;

	//1���ȶ����������ͣ��������Ͷ���ָ�����
	typedef int A[10]; //A�������ͣ�[10]������
	A *p = NULL; //p�������ͱ���
	//p = a; //a������Ԫ�ص�ַ�� a��&aһ��������Ҳ����&a�����ڱ�����о���
	p = &a; // ���������׵�ַ

	for (i = 0; i < 10; i++)
	{
		(*p)[i] = i + 1; // ���������ͱ�����ֵ
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
//����ָ��:���巽��2
int main()
{
	int a[10] = { 0 };
	int i = 0;

	//2���ȶ�������ָ�����ͣ��������Ͷ���ָ�����
	//() �� []���ȼ�һ������������
	typedef int(*P)[10];
	P q;//����ָ�����
	q = &a;

	for (i = 0; i < 10; i++)
	{
		(*q)[i] = 2*i + 1; // ���������ͱ�����ֵ
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*q)[i]);
	}

	system("pause");
	return 0;
}
*/