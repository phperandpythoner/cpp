#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
/*
//在c编译器不会报错，但c++会报错，g_a被重定义
//int g_a; //bss段
//int g_a = 10; //data
//c++语言对全局变量的定义检测能力增强了
int g_a = 10;

//c++语言使用结构体时定义变量，可以不用加struct关键字
struct Teacher {
	int id;
	char name[64];
};


//对函数定义类型增强
int fun()
{
	return 10;
}
*/

#if 0
//c语言未定义函数类型，默认时int类型
fun()
{
	return 10;
}
#endif

//c++对函数参数增强，函数形参对应函数实参个数
#if 0
//c语言代码：
int fun(int a)
{
	return a;
}
//fun(10, 20, 30);可以这样调用,可以传递多个参数
#endif


//c++增加了bool类型，true:1,false:0;任何非0的都会转换成值为：1


//三目运算符的增强
#if 0
//c语言代码
int main()
{
	int a = 10, b = 20, c = 0;
	c = a < b ? a : b;

	//左值 右值 ：等号 = 左边的为左值，右边的为右值
	(a < b ? a : b) = 50; //会报错 10 = 50

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

	// 如果是左值，则a相当于是变量，a = 50
	(a < b ? a : b) = 50; 
	std::cout << "a=" << a << std::endl;
}
#endif

//c++const的增强,c++不能通过指针修改const修饰的变量
//c++中const修饰的变量会放到常量区的符号表里，符号表有key value，分别对应 key = a, value = 10
#if 0
//c语言可以通过指针修改const修饰的变量值
int const a = 10;
int *p = NULL;
p = &a;
*p = 20;

int arr[a] = { 0 }; //会报错，因为a可以被改变

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

	int arr[a] = { 0 }; //不会报错

	system("pause");
	return 0;
}
#endif


//枚举的增强，对枚举初始化变量必须是枚举内的成员
#if 0
//c语言枚举类型的定义和使用
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
	//enum season s = 2; //"int" 类型的值不能用于初始化 "season" 类型的实体
	enum season s = AUT;
	//if (s == 2) //不能将 "int" 类型的值分配到 "season" 类型的实体
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