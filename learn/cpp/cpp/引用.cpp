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
	cout << "指针打印 " << "id: " << p->id << " name: " << p->name << endl;
	return;
}

void printS2(teacher & p)
{
	cout << "引用打印" << "id: " << p.id << " name: " << p.name << endl;
	return;
}

char *test()
{
	char *p = NULL;
	p = (char *)malloc(30);
	return p;
}

//引用作为函数的返回值
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
	//1、引用声明，已经声明，不可改变
	int &re = a; // re就是a的别名
	//int &re; //这样定义会报错，必须要初始化，跟const定义一样
	re = 11;

	cout << "a = " << a << endl;
	cout << "re = " << re << endl;

	int b = 20;
	re = b; // 让re称为变量b的别名是否可以？在定义了引用是谁的变量别名时不可以在重新定义其他变量的别名
	re = 21;

	cout << "b = " << b << endl;
	cout << "re = " << re << endl;
	//b = 20
	//re = 21

	int &re2 = a; //2、一个变量可以具有多个别名
	re2 = 12;
	cout << "a = " << a << endl;
	cout << "re2 = " << re2 << endl;

	//3、&前有数据类型时，时引用；其他情况都是区地址

	cout << "-----------------------------------" << endl;

	int c = 10;
	cout << "c = " << c << endl;
	change_value(&c);
	cout << "指针改变值 c = " << c << endl;
	change_value2(c);
	cout << "引用改变值 c = " << c << endl;

	cout << "-----------------------------------" << endl;

	teacher t = { 1, "zhang3" };
	printS(&t);
	printS2(t);

	cout << "-----------------------------------" << endl;
	cout << "引用本质" << endl;

	cout << "sizeof(typeA) = " << sizeof(typeA) << endl;
	cout << "sizeof(typeB) = " << sizeof(typeB) << endl;

	cout << "-----------------------------------" << endl;
	char *p = test();
	cout << &p << endl;

	int d = 0;
	d = test2(); // 值拷贝
	cout << "引用作为函数的返回值 d = " << d << endl;

	int & e = test3();
	cout << "引用作为函数的返回值 e = " << e << endl;

	cout << "-----------------------------------" << endl;
	cout << "指针引用" << endl;

	teacher *t2;
	getval(&t2);
	cout << "指针 id:" << t2->id << " name:" << t2->name << endl;
	freeval(&t2);

	teacher *t3;
	getval2(t3);
	cout << "引用 id:" << t3->id << " name:" << t3->name << endl;
	freeval2(t3);

	system("pause");
	return 0;
}
*/