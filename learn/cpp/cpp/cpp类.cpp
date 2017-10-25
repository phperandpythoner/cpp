#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>

/*
using namespace std;

//类中有默认的构造函数和默认的拷贝构造函数，当定义了就会显示，默认的就会消失

class Test {
public:
	//构造函数：与类名相同，定义不带类型，没有返回值

	//构造函数--不带参数
	Test()
	{
		m_x = 0;
		m_y = 0;
		name = (char *)malloc(30);
		strcpy(name, "zhang3");
	}

	//构造函数--带参数
	Test(int a, int b)
	{
		m_x = a;
		m_y = b;
		name = (char *)malloc(30);
		strcpy(name, "zhang4");
	}

	//构造函数--带参数，支持函数重载
	Test(int a)
	{
		m_x = a;
		name = (char *)malloc(30);
		strcpy(name, "zhang5");
	}

	//拷贝构造函数
	Test(const Test& another)
	{
		m_x = another.m_x;
		m_y = another.m_y;
		name = (char *)malloc(30);
		strcpy(name, "zhang6");
		cout << "拷贝构造函数: Test(const Test& another)" << endl;
	}

	//赋值操作
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

	//析构函数：和函数名相同，但前面需要加上 ~ ，定义不带类型，没有返回值，没有参数
	~Test()
	{
		cout << "~Test()....." << endl;
		if (name != NULL)
		{
			cout << "name:" << name << " 释放成功！" << endl;
			free(name);
		}
	}


private:
	int m_x;
	int m_y;
	char *name;
};

//拷贝构造函数应用场景
//场景1
//析构函数调用顺序，跟构造函数相反，谁先构造，谁后析构
void test1()
{
	Test t1(11, 22);
	t1.printTest();

	Test t2(t1);
	t2.printTest();
}

//场景2
void test2()
{
	Test t1(22, 33);

	Test t2;
	t2 = t1;//赋值
	t2.printTest();
}

//场景3
void fun(Test t1) // Test t1 = Test::t1   Test t1是拷贝构造函数
{
	cout << "fun begin ...." << endl;
	t1.printTest();
	cout << "fun end ...." << endl;
}
void test3()
{
	cout << "test3 begin ...." << endl;
	Test t1(33, 44);
	fun(t1);//这里会调用析构函数
	cout << "test3 end ...." << endl;
}

//场景4
Test fun2()
{
	cout << "fun2 begin ...." << endl;
	Test tmp(55, 66);
	tmp.printTest();
	cout << "fun2 end ...." << endl;

	return tmp;
}//匿名的对象 = tmp
void test4()
{
	cout << "test4 begin ...." << endl;
	//返回一个匿名对象，当函数返回一个匿名对象时，函数外部没有任何变量去接收它，这个匿名对象将不会被使用，（找不到），
	//编译器会直接将这个匿名对象回收，而不是等待整个函数执行完毕后回收
	fun2();
	cout << "test4 end ...." << endl;
}

void test5()
{
	cout << "test5 begin ...." << endl;
	//这个不是拷贝构造函数，而是将匿名对象用变量t1接收
	Test t1 = fun2();
	cout << "test5 end ...." << endl;
}


//构造函数的初始化列表
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



//new和delete关键字
//c语言在堆上分配空间
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

	//指针数组
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
//c++在堆上分配空间
void test7()
{
	int * a = new int; //new在堆上分配空间
	*a = 10;
	cout << "*a = " << *a << endl;
	if (a != NULL)
	{
		delete a; //释放堆上空间
		a = NULL;
	}
	cout << "--------" << endl;

	//指针数组
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

	//c++可以对构造函数初始化赋值，malloc函数则不可以
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

	//拷贝构造函数
	Test t4(t1);
	t4.printTest();

	//构造函数是对象初始化时调用
	Test t5 = t2; //这种方法也是 拷贝构造函数
	t5.printTest();

	//赋值操作,这种不是拷贝构造函数
	Test t6;
	t6 = t2;
	t6.printTest();

	cout << "--------------------" << endl;

	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	cout << "-------------------- 构造函数的初始化列表 ———————————" << endl;
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