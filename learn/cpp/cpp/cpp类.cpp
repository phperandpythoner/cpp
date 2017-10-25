#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>

/*
using namespace std;

//������Ĭ�ϵĹ��캯����Ĭ�ϵĿ������캯�����������˾ͻ���ʾ��Ĭ�ϵľͻ���ʧ

class Test {
public:
	//���캯������������ͬ�����岻�����ͣ�û�з���ֵ

	//���캯��--��������
	Test()
	{
		m_x = 0;
		m_y = 0;
		name = (char *)malloc(30);
		strcpy(name, "zhang3");
	}

	//���캯��--������
	Test(int a, int b)
	{
		m_x = a;
		m_y = b;
		name = (char *)malloc(30);
		strcpy(name, "zhang4");
	}

	//���캯��--��������֧�ֺ�������
	Test(int a)
	{
		m_x = a;
		name = (char *)malloc(30);
		strcpy(name, "zhang5");
	}

	//�������캯��
	Test(const Test& another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
		name = (char *)malloc(30);
		strcpy(name, "zhang6");
		cout << "�������캯��: Test(const Test& another)" << endl;
	}

	//��ֵ����
	void operator=(const Test& another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
		name = (char *)malloc(30);
		strcpy(name, "zhang7");
	}

	void printTest()
	{
		cout << "x = " << m_x << ", y = " << m_y << ", name = " << name << endl;
		return;
	}

	//�����������ͺ�������ͬ����ǰ����Ҫ���� ~ �����岻�����ͣ�û�з���ֵ��û�в���
	~Test()
	{
		cout << "~Test()....." << endl;
		if (name != NULL)
		{
			cout << "name:" << name << " �ͷųɹ���" << endl;
			free(name);
		}
	}


private:
	int m_x;
	int m_y;
	char *name;
};

//�������캯��Ӧ�ó���
//����1
//������������˳�򣬸����캯���෴��˭�ȹ��죬˭������
void test1()
{
	Test t1(11, 22);
	t1.printTest();

	Test t2(t1);
	t2.printTest();
}

//����2
void test2()
{
	Test t1(22, 33);

	Test t2;
	t2 = t1;//��ֵ
	t2.printTest();
}

//����3
void fun(Test t1) // Test t1 = Test::t1   Test t1�ǿ������캯��
{
	cout << "fun begin ...." << endl;
	t1.printTest();
	cout << "fun end ...." << endl;
}
void test3()
{
	cout << "test3 begin ...." << endl;
	Test t1(33, 44);
	fun(t1);//����������������
	cout << "test3 end ...." << endl;
}

//����4
Test fun2()
{
	cout << "fun2 begin ...." << endl;
	Test tmp(55, 66);
	tmp.printTest();
	cout << "fun2 end ...." << endl;

	return tmp;
}//�����Ķ��� = tmp
void test4()
{
	cout << "test4 begin ...." << endl;
	//����һ���������󣬵���������һ����������ʱ�������ⲿû���κα���ȥ������������������󽫲��ᱻʹ�ã����Ҳ�������
	//��������ֱ�ӽ��������������գ������ǵȴ���������ִ����Ϻ����
	fun2();
	cout << "test4 end ...." << endl;
}

void test5()
{
	cout << "test5 begin ...." << endl;
	//������ǿ������캯�������ǽ����������ñ���t1����
	Test t1 = fun2();
	cout << "test5 end ...." << endl;
}


//���캯���ĳ�ʼ���б�
class A {
	int &x;
public:
	A(int a):x(a)
	{
		m_a = a;
		cout << "A()..." << endl;
	}
	void printA()
	{
		cout << "a = " << m_a << endl;
		cout << "x = " << this->x << endl;
	}
	~A()
	{
		cout << "~A()..." << endl;
	}
private:
	int m_a;
};

class B {
public:
	
	B(A& a1, A& a2, int b) : m_a1(a1), m_a2(a2)
	{
		m_b = b;
		cout << "B()..." << endl;
	}

	B(int a, int b, int c) :m_a1(a), m_a2(b)
	{
		m_b = c;
		cout << "B()..." << endl;
	}

	void printB()
	{
		cout << "b = " << m_b << endl;
		m_a1.printA();
		m_a2.printA();
	}

	~B()
	{
		cout << "~B()..." << endl;
	}
private:
	int m_b;
	A m_a1;
	A m_a2;
};



//new��delete�ؼ���
//c�����ڶ��Ϸ���ռ�
void test6()
{
	char *p = NULL;
	p = (char *)malloc(sizeof(char));
	*p = 'a';
	printf("*p = %c\n", *p);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	printf("-------\n");

	//ָ������
	char *pa = (char *)malloc(sizeof(char) * 10);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		pa[i] = 'a' + i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%c ", pa[i]);
	}
	printf("\n");

	if (pa != NULL)
	{
		free(pa);
		pa = NULL;
		printf("free()...\n");
	}
}
//c++�ڶ��Ϸ���ռ�
void test7()
{
	int * a = new int; //new�ڶ��Ϸ���ռ�
	*a = 10;
	cout << "*a = " << *a << endl;
	if (a != NULL)
	{
		delete a; //�ͷŶ��Ͽռ�
		a = NULL;
	}
	cout << "--------" << endl;

	//ָ������
	char * pa = new char[10];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		pa[i] = 'a' + i;
	}
	for (i = 0; i < 10; i++)
	{
		cout << pa[i] << endl;
	}
	if (pa != NULL)
	{
		delete pa;
		pa = NULL;
		cout << "delete ..." << endl;
	}

	cout << "--------------------" << endl;

	//c++���ԶԹ��캯����ʼ����ֵ��malloc�����򲻿���
	Test *t = new Test(10);
	t->printTest();
	if (t != NULL)
	{
		delete t;
		t = NULL;
		cout << "delete Test ..." << endl;
	}
}


int main()
{
	Test t1;
	t1.printTest();

	Test t2(10, 20);
	t2.printTest();

	Test t3(30);
	t3.printTest();

	//�������캯��
	Test t4(t1);
	t4.printTest();

	//���캯���Ƕ����ʼ��ʱ����
	Test t5 = t2; //���ַ���Ҳ�� �������캯��
	t5.printTest();

	//��ֵ����,���ֲ��ǿ������캯��
	Test t6;
	t6 = t2;
	t6.printTest();

	cout << "--------------------" << endl;

	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	cout << "-------------------- ���캯���ĳ�ʼ���б� ����������������������" << endl;
	//A a1(10), a2(20);
	//B b1(a1, a2, 200);//B(a1, a2, 100);
	//b1.printB();

	B b2(10, 20, 100);
	b2.printB();

	cout << "---------------------------------" << endl;
	test6();
	test7();

	system("pause");
	return 0;
}
*/