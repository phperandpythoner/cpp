#include <stdio.h>

//�����ı���
//��������������д�ܶ����ڴ���󣬳�Ϊ�������ܶ�����д�ĳ�Ϊ����

void main01()
{
	int a;
	char *p;

	//ֱ�Ӹ�ֵ
	a = 10;
	printf("a=%d\n", a);
	printf("&a = %d\n", &a);//&a = 11926428

	//��Ӹ�ֵ
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