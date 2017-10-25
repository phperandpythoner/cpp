#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

/*
//内联函数
inline char * dbtest(int a)
{
	return (a % 2 > 0 ? "奇" : "偶");
}

int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		std::cout << i << "是" << dbtest(i) << std::endl;
	}

	system("pause");
	return 0;
}
*/

/*
//占位参数
int test1(int a, int)
{
	return a;
}

int main()
{
	std::cout << test1(10, 11) << std::endl;

	system("pause");
	return 0;
}
*/


/*
//函数重载
//函数的返回值，函数形参列表（参数的个数，参数类型，参数顺序）
//函数重载：函数名相同，参数列表不同
//函数的返回值并不是构成函数重载的条件
int fun(int a, int b)
{
	std::cout << "a + b = " << a + b << std::endl;
	 return 0;
}

char fun(int a, char b)
{
	std::cout << "a = " << a << "b = " << b << std::endl;
	return 0;
}

int main()
{
	fun(1, 2);
	fun(1, 'a');

	system("pause");
	return 0;
}
*/


/*
//函数重载和函数指针
int fun(int a, int b)
{
	std::cout << "fun" << a << b << std::endl;
	return 0;
}
int fun(int a, char b)
{
	std::cout << "fun" << a << b << std::endl;
	return 0;
}

//1、定义一个函数类型
typedef int(TYPE_FUNC)(int a, int b);

//2、顶一个函数指针类型
typedef int(*TYPE_FUNC_P)(int a, int b);

int main()
{
	//1、
	TYPE_FUNC *f1 = NULL;
	f1 = fun;
	f1(10,20);

	std::cout << "-----------------------" << std::endl;
	
	//2、
	TYPE_FUNC_P p1 = NULL;
	p1 = fun;
	p1(30, 40);

	std::cout << "-----------------------" << std::endl;

	//3、
	int(*p2)(int a, char);
	p2 = NULL;
	p2 = fun;
	p2(50, 'a');

	system("pause");
	return 0;
}
*/


//this、全局函数、成员函数
class Test {
private:
	int m;
	int aa;
	int bb;

public:
	Test(int a)
	{
		this->m = a;
	}
	Test(int a, int b)
	{
		this->aa = a;
		this->bb = b;
	}

	int getM() const
	{
		//this->m = 100; //this指针不是 const Test *,所以可以对指针所指的空间修改内容
		//this++; // this指针是一个常指针， Test * const this，所以不能修改this里的内容
		return this->m;
	}

	int getA()
	{
		return this->aa;
	}

	int getB()
	{
		return this->bb;
	}

	void printTest()
	{
		cout << "aa = " << this->aa << " bb = " << this->bb << endl;
	}

	Test addTest2(Test &t1, Test &t2)
	{
		Test tmp(t1.getA()+t2.getA(), t1.getB()+t2.getB());
		return tmp;
	}

	Test addTest3(Test &another)
	{
		Test tmp(this->aa + another.getA(), this->bb + another.getB());

		return tmp;
	}

	//累加+=
	void addTest4(Test &another)
	{
		this->aa += another.getA();
		this->bb += another.getB();
	}

	Test & addTest5(Test &another)
	{
		this->aa += another.getA();
		this->bb += another.getB();

		//如果是想返回一个对象本身，在成员方法中，使用*this返回
		return *this;
	}

};

Test addTest(Test &t1, Test &t2)
{
	Test tmp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return tmp;
}//返回一个匿名对象

int main()
{
	cout << "this 练习" << endl;
	Test a(10);
	int m = a.getM();
	cout << m << endl;

	cout << "---------------------------------------" << endl;

	Test t1(10, 20);
	Test t2(100, 200);
	Test t(22, 33);

	Test t3 = addTest(t1, t2);
	t3.printTest();

	Test t4 = t1.addTest2(t1, t2);
	t4.printTest();

	//t1.addTest3(t2)返回的是一个匿名对象 tmp = t1.addTest3(t2); tmp.addTest3(t);
	Test t5 = t1.addTest3(t2).addTest3(t);
	t5.printTest();

	t5.addTest4(t);
	t5.printTest();

	t5.addTest5(t1).addTest5(t2);
	t5.printTest();

	system("pause");
	return 0;
}