#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
/*
//��c���������ᱨ����c++�ᱨ��g_a���ض���
//int g_a; //bss��
//int g_a = 10; //data
//c++���Զ�ȫ�ֱ����Ķ�����������ǿ��
int g_a = 10;

//c++����ʹ�ýṹ��ʱ������������Բ��ü�struct�ؼ���
struct Teacher {
	int id;
	char name[64];
};


//�Ժ�������������ǿ
int fun()
{
	return 10;
}
*/

#if 0
//c����δ���庯�����ͣ�Ĭ��ʱint����
fun()
{
	return 10;
}
#endif

//c++�Ժ���������ǿ�������βζ�Ӧ����ʵ�θ���
#if 0
//c���Դ��룺
int fun(int a)
{
	return a;
}
//fun(10, 20, 30);������������,���Դ��ݶ������
#endif


//c++������bool���ͣ�true:1,false:0;�κη�0�Ķ���ת����ֵΪ��1


//��Ŀ���������ǿ
#if 0
//c���Դ���
int main()
{
	int a = 10, b = 20, c = 0;
	c = a < b ? a : b;

	//��ֵ ��ֵ ���Ⱥ� = ��ߵ�Ϊ��ֵ���ұߵ�Ϊ��ֵ
	(a < b ? a : b) = 50; //�ᱨ�� 10 = 50

	return 0;
}
#endif
#if 0
//c++
void test1()
{
	int a = 10, b = 20, c = 0;
	c = a < b ? a : b;
	std::cout << "a=" << c << std::endl;

	// �������ֵ����a�൱���Ǳ�����a = 50
	(a < b ? a : b) = 50; 
	std::cout << "a=" << a << std::endl;
}
#endif

//c++const����ǿ,c++����ͨ��ָ���޸�const���εı���
//c++��const���εı�����ŵ��������ķ��ű�����ű���key value���ֱ��Ӧ key = a, value = 10
#if 0
//c���Կ���ͨ��ָ���޸�const���εı���ֵ
int const a = 10;
int *p = NULL;
p = &a;
*p = 20;

int arr[a] = { 0 }; //�ᱨ����Ϊa���Ա��ı�

#endif
#if 0
//c++
int main()
{
	const int a = 10;
	int *p = (int *)&a;
	*p = 20;
	std::cout << "a = " << a << std::endl;
	std::cout << "*p = " << *p << std::endl;
	//a = 10
	//*p = 20

	int arr[a] = { 0 }; //���ᱨ��

	system("pause");
	return 0;
}
#endif


//ö�ٵ���ǿ����ö�ٳ�ʼ������������ö���ڵĳ�Ա
#if 0
//c����ö�����͵Ķ����ʹ��
enum season {
	SPR = 0,
	SUM,
	AUT,
	WIN,
};
void test2()
{
	enum season s = 2;
	if (s == 2)
	{

	}
}
#endif
#if 0
//c++
enum season {
	SPR = 0,
	SUM,
	AUT,
	WIN,
};
void test2()
{
	//enum season s = 2; //"int" ���͵�ֵ�������ڳ�ʼ�� "season" ���͵�ʵ��
	enum season s = AUT;
	//if (s == 2) //���ܽ� "int" ���͵�ֵ���䵽 "season" ���͵�ʵ��
	if(s = AUT)
	{

	}
}
#endif

/*
int main()
{
	Teacher t1;
	t1.id = 1;
	strcpy(t1.name, "xiaohua");

	test1();

	system("pause");
	return 0;
}
*/