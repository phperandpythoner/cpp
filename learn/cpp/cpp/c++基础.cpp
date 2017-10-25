#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

/*
//��������
inline char * dbtest(int a)
{
	return (a % 2 > 0 ? "��" : "ż");
}

int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		std::cout << i << "��" << dbtest(i) << std::endl;
	}

	system("pause");
	return 0;
}
*/

/*
//ռλ����
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
//��������
//�����ķ���ֵ�������β��б������ĸ������������ͣ�����˳��
//�������أ���������ͬ�������б�ͬ
//�����ķ���ֵ�����ǹ��ɺ������ص�����
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
//�������غͺ���ָ��
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

//1������һ����������
typedef int(TYPE_FUNC)(int a, int b);

//2����һ������ָ������
typedef int(*TYPE_FUNC_P)(int a, int b);

int main()
{
	//1��
	TYPE_FUNC *f1 = NULL;
	f1 = fun;
	f1(10,20);

	std::cout << "-----------------------" << std::endl;
	
	//2��
	TYPE_FUNC_P p1 = NULL;
	p1 = fun;
	p1(30, 40);

	std::cout << "-----------------------" << std::endl;

	//3��
	int(*p2)(int a, char);
	p2 = NULL;
	p2 = fun;
	p2(50, 'a');

	system("pause");
	return 0;
}
*/


//this��ȫ�ֺ�������Ա����
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
		//this->m = 100; //thisָ�벻�� const Test *,���Կ��Զ�ָ����ָ�Ŀռ��޸�����
		//this++; // thisָ����һ����ָ�룬 Test * const this�����Բ����޸�this�������
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

	//�ۼ�+=
	void addTest4(Test &another)
	{
		this->aa += another.getA();
		this->bb += another.getB();
	}

	Test & addTest5(Test &another)
	{
		this->aa += another.getA();
		this->bb += another.getB();

		//������뷵��һ���������ڳ�Ա�����У�ʹ��*this����
		return *this;
	}

};

Test addTest(Test &t1, Test &t2)
{
	Test tmp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return tmp;
}//����һ����������

int main()
{
	cout << "this ��ϰ" << endl;
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

	//t1.addTest3(t2)���ص���һ���������� tmp = t1.addTest3(t2); tmp.addTest3(t);
	Test t5 = t1.addTest3(t2).addTest3(t);
	t5.printTest();

	t5.addTest4(t);
	t5.printTest();

	t5.addTest5(t1).addTest5(t2);
	t5.printTest();

	system("pause");
	return 0;
}