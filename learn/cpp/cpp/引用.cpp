#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
/*
using namespace std;

struct teacher {
	int id;
	char name[64];
};

struct typeA {
	int *a;
};

struct typeB {
	int &a;
};

void change_value(int *p)
{
	*p = 100;
	return;
}

void change_value2(int &p)
{
	p = 200;
	return;
}

void printS(teacher *p)
{
	cout << "ָ���ӡ " << "id: " << p->id << " name: " << p->name << endl;
	return;
}

void printS2(teacher & p)
{
	cout << "���ô�ӡ" << "id: " << p.id << " name: " << p.name << endl;
	return;
}

char *test()
{
	char *p = NULL;
	p = (char *)malloc(30);
	return p;
}

//������Ϊ�����ķ���ֵ
int & test2()
{
	int a = 10;
	return a;
} // int &tmp=a;

int & test3()
{
	static int age = 22;
	return age;
}

int getval(teacher **p)
{
	teacher *pp = NULL;
	pp = (teacher *)malloc(sizeof(teacher));
	if (pp == NULL)
	{
		return -1;
	}

	pp->id = 10;
	strcpy(pp->name, "zhao4");

	*p = pp;
	return 0;
}

int freeval(teacher **p)
{
	if (p == NULL)
	{
		return -1;
	}
	teacher *pp = *p;
	if (pp != NULL)
	{
		free(pp);
		p = NULL;
	}

	return 0;
}

int getval2(teacher * &p)
{
	p = (teacher *)malloc(sizeof(teacher));
	if (p == NULL)
	{
		return -1;
	}
	p->id = 11;
	strcpy(p->name, "wang5");

	return 0;
}

int freeval2(teacher * &p)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	return 0;
}

int main()
{
	int a = 10;
	//1�������������Ѿ����������ɸı�
	int &re = a; // re����a�ı���
	//int &re; //��������ᱨ������Ҫ��ʼ������const����һ��
	re = 11;

	cout << "a = " << a << endl;
	cout << "re = " << re << endl;

	int b = 20;
	re = b; // ��re��Ϊ����b�ı����Ƿ���ԣ��ڶ�����������˭�ı�������ʱ�����������¶������������ı���
	re = 21;

	cout << "b = " << b << endl;
	cout << "re = " << re << endl;
	//b = 20
	//re = 21

	int &re2 = a; //2��һ���������Ծ��ж������
	re2 = 12;
	cout << "a = " << a << endl;
	cout << "re2 = " << re2 << endl;

	//3��&ǰ����������ʱ��ʱ���ã����������������ַ

	cout << "-----------------------------------" << endl;

	int c = 10;
	cout << "c = " << c << endl;
	change_value(&c);
	cout << "ָ��ı�ֵ c = " << c << endl;
	change_value2(c);
	cout << "���øı�ֵ c = " << c << endl;

	cout << "-----------------------------------" << endl;

	teacher t = { 1, "zhang3" };
	printS(&t);
	printS2(t);

	cout << "-----------------------------------" << endl;
	cout << "���ñ���" << endl;

	cout << "sizeof(typeA) = " << sizeof(typeA) << endl;
	cout << "sizeof(typeB) = " << sizeof(typeB) << endl;

	cout << "-----------------------------------" << endl;
	char *p = test();
	cout << &p << endl;

	int d = 0;
	d = test2(); // ֵ����
	cout << "������Ϊ�����ķ���ֵ d = " << d << endl;

	int & e = test3();
	cout << "������Ϊ�����ķ���ֵ e = " << e << endl;

	cout << "-----------------------------------" << endl;
	cout << "ָ������" << endl;

	teacher *t2;
	getval(&t2);
	cout << "ָ�� id:" << t2->id << " name:" << t2->name << endl;
	freeval(&t2);

	teacher *t3;
	getval2(t3);
	cout << "���� id:" << t3->id << " name:" << t3->name << endl;
	freeval2(t3);

	system("pause");
	return 0;
}
*/