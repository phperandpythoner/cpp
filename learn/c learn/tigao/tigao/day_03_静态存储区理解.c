#include <stdio.h>

//ָ��ָ��˭���Ͱ�˭�ĵ�ַ��ֵ��ָ��
//ָ����� �� ����ָ����ڴ�ռ������������ͬ�ĸ���

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

	//��ӡ����p1,p2���ڴ�ռ������
	printf("p1=%s, p2=%s\n", p1, p2);
	//p1=abc, p2=abc
	
	//��ӡp1,p2��ֵ
	printf("p1=%d, p2=%d\n", p1, p2);
	//p1=10582872, p2=10582872
	
	system("pause");
}