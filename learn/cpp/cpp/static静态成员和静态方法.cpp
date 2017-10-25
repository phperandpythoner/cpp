/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Student {
public:
	Student(int stu_id, double stu_score)
	{
		id = stu_id;
		score = stu_score;

		m_count++;
		total_score += score;
	}

	static int getCount()
	{
		return m_count;
	}

	static double getTotalScore()
	{
		return total_score;
	}

	~Student()
	{
		cout << "~Student()..." << endl;
	}

private:
	//学生id
	int id;
	//学生分数
	double score;

	//学生总人数
	static int m_count;
	//学生总分数
	static double total_score;
};

//静态属性变量在类外面赋值
int Student::m_count = 0;
double Student::total_score = 0.0;

int main()
{
	Student s1(1, 80);
	Student s2(2, 90);
	Student s3(3, 100);

	cout << "学生总人数：" << Student::getCount() << endl;
	cout << "学生总分数：" << Student::getTotalScore() / Student::getCount() << endl;


	system("pause");
	return 0;
}
*/