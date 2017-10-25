#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

/*
//命名空间使用方式1
//using namespace std;

int main()
{
	//cout << "hello world!" << endl;

	//命名空间使用方式2
	//std::cout << "hello world!" << std::endl;

	//命名空间使用方式3（可以写在main()外面）
	using std::cout;
	using std::endl;
	cout << "hello c++!" << endl;

	system("pause");
	return 0;
}
*/



/*
using namespace std;

//命名空间定义
namespace spaceA {
	int a = 10;
}

namespace spaceB {
	int b = 0;
	namespace spaceC {
		struct teacher {
			int id;
			char name[64];
		};
	}

	namespace spaceD {
		struct teacher {
			int id;
			char name[64];
		};
	}
}

int main()
{
	using namespace spaceA;
	a += 1;
	cout << a << endl;

	//方式1
	spaceB::spaceC::teacher t1;

	t1.id = 10;
	strcpy(t1.name, "mr.wang");
	cout << "name:" << t1.name << " " << "id:" << t1.id << endl;

	//方式2
	using namespace spaceB::spaceD;
	spaceB::spaceD::teacher t2;

	t2.id = 11;
	strcpy(t2.name, "ms.zhang");
	cout << "name:" << t2.name << " " << "id:" << t2.id << endl;

	//方式3
	using spaceB::spaceC::teacher;
	teacher t3;

	t3.id = 13;
	strcpy(t3.name, "ms.li");
	cout << "name:" << t3.name << " " << "id:" << t3.id << endl;

	system("pause");
	return 0;
}
*/