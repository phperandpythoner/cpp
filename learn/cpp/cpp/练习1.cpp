/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Goods {
public:
	Goods()
	{
		next = NULL;
		weight = 0;
		cout << "创建一个重量为" << weight << "的货物" << endl;
	}

	Goods(int w)
	{
		weight = w;
		next = NULL;
		total_weight += w;
		cout << "创建一个重量为" << weight << "的货物" << endl;
	}

	~Goods()
	{
		cout << "减少一个重量为" << weight << "的货物" << endl;
		total_weight -= weight;
	}

	static int get_total_weight()
	{
		return total_weight;
	}

	Goods *next;
private:
	int weight;
	static int total_weight;
};

int Goods::total_weight = 0;

void buy(Goods * &head, int w)
{
	Goods *new_goods = new Goods(w);
	if (head == NULL)
	{
		head = new_goods;
	}
	else
	{
		new_goods->next = head;
		head = new_goods;
	}
}

void sale(Goods * &head)
{
	if (head == NULL)
	{
		cout << "仓库里已经没有货物了" << endl;
		return;
	}

	Goods *tmp = head;
	head = head->next;

	delete tmp;
}

int main()
{
	int choice = 0;
	Goods *head = NULL;

	do {
		cout << "1--进货" << endl;
		cout << "2--出货" << endl;
		cout << "0--退出" << endl;
		cin >> choice;
		int w = 0;

		switch (choice)
		{
		case 1:
			cout << "请输入要创建货物的重量" << endl;
			cin >> w;
			buy(head, w);
			break;
		case 2:
			sale(head);
			break;
		case 0:
			return 0;
		default:
			break;
		}

		cout << "仓库现在的货物重量为" << Goods::get_total_weight() << endl;
	} while (1);


	system("pause");
	return 0;
}
*/