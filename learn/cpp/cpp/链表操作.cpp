/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef struct Node {
	int id;
	Node * next;
}Node;

//创建头结点
Node *createList()
{
	Node *head = NULL;
	head = new Node;

	if (head == NULL)
	{
		return NULL;
	}

	//给head成员赋值
	head->id = -1;
	head->next = NULL;

	//创建当前结点和新结点
	Node *pcur = head;
	Node *pnew = NULL;

	int data;
	while (1)
	{
		cout << "请输入数据：" << endl;
		cin >> data;
		if (data == -1)
		{
			break;
		}

		pnew = new Node;
		if (pnew == NULL)
		{
			continue;
		}

		pnew->id = data;
		pnew->next = NULL;

		//当前结点的next指向pNew
		pcur->next = pnew;

		//把pCur移动到pNew，pCur指向pNew
		pcur = pnew;
	}

	return head;
}

int printList(Node *head)
{
	if (head == NULL)
	{
		return -1;
	}

	//头结点不打印，取出第一个有效节点（头结点next）
	Node *pcur = head->next;

	cout << "->" << endl;
	//不能使用pcur->next != NULL，因为最后一个结点的指针域指向的是NULL，如果这个作为判断条件则少打印了末尾结点
	while (pcur != NULL)
	{
		cout << pcur->id << "->" << endl;

		pcur = pcur->next;
	}

	return 0;
}

//在指定x结点位置插入结点y
int insertPosList(Node *head, int x, int y)
{
	if (head == NULL)
	{
		return -1;
	}

	//创建两个结点，ppre上一个结点，pcur当前结点
	Node *ppre = head;
	Node *pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id == x)
		{
			break;
		}

		//没有找到指定插入的结点，则在链表末尾插入结点
		ppre = pcur;
		pcur = pcur->next;
	}

	//创建一个新结点
	Node *pnew = NULL;
	pnew = new Node;
	if (pnew == NULL)
	{
		return -2;
	}
	pnew->id = y;
	pnew->next = NULL;

	ppre->next = pnew;
	pnew->next = pcur;

	return 0;
}

//删除指定结点x
int delPosList(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *ppre = head;
	Node *pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id == x)
		{
			ppre->next = pcur->next;
			delete pcur;
			pcur = NULL;

			break;
		}

		//pPre指向pCur位置,执行下一次循环操作
		ppre = pcur;
		pcur = pcur->next;
	}

	return 0;
}

//删除指定的所有结点
//让上一个结点指向当前结点的下一个结点ppre->next = pcur->next;
//重新给pCur指向下一个结点，pcur = ppre->next
int delPosProList(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *ppre = head;
	Node *pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id == x)
		{
			ppre->next = pcur->next;
			delete pcur;
			pcur = NULL;

			pcur = ppre->next;

			continue;
		}

		ppre = pcur;
		pcur = pcur->next;
	}

	return 0;
}

//清空链表
int clearList(Node *head)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *tmp = NULL;
	int i = 0;

	while (head != NULL)
	{
		tmp = head->next;
		delete head;
		head = tmp;

		i++;
	}

	cout << "释放了" << i << "个结点" << endl;

	return 0;
}

//排序
int sortList(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return -1;
	}

	Node tmp;
	Node *ppre = NULL;
	Node *pcur = NULL;
	
	for (ppre = head->next; ppre->next != NULL; ppre = ppre->next)
	{
		for (pcur = ppre->next; pcur != NULL; pcur = pcur->next)
		{
			if (ppre->id > pcur->id)
			{
				//只交换数据域数据
				tmp.id = pcur->id;
				pcur->id = ppre->id;
				ppre->id = tmp.id;
			}
		}
	}


	return 0;
}

//升序插入结点
int insertPosSortList(Node *head, int x)
{
	int ret = sortList(head);
	if (ret != 0)
	{
		return ret;
	}

	if (head == NULL)
	{
		return -1;
	}

	//创建两个结点，ppre上一个结点，pcur当前结点
	Node *ppre = head;
	Node *pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id > x)
		{
			break;
		}

		//没有找到指定插入的结点，则在链表末尾插入结点
		ppre = pcur;
		pcur = pcur->next;
	}

	//创建一个新结点
	Node *pnew = NULL;
	pnew = new Node;
	if (pnew == NULL)
	{
		return -2;
	}
	pnew->id = x;
	pnew->next = NULL;

	ppre->next = pnew;
	pnew->next = pcur;

	return ret;
}

//翻转链表
int reverseList(Node *head)
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return -1;
	}

	Node *ppre = head->next;
	Node *pcur = ppre->next;
	//第一个结点为末尾结点
	ppre->next = NULL;
	Node *tmp = NULL;

	while (pcur != NULL)
	{
		//把当前结点pcur的下一个结点拷贝给tmp
		tmp = pcur->next;
		//当前结点则指向上一个结点ppre
		pcur->next = ppre;

		//重新分配
		ppre = pcur;
		pcur = tmp;
	}

	//重新指向头结点，头结点指向当前结点ppre
	head->next = ppre;

	return 0;
}

int main()
{
	Node *head = NULL;
	head = createList();
	printList(head);

	cout << "在指定结点5位置插入结点4" << endl;
	insertPosList(head, 5, 4);
	printList(head);

	cout << "删除指定结点3" << endl;
	delPosList(head, 3);
	printList(head);

	cout << "删除指定结点9的所有" << endl;
	delPosProList(head, 9);
	printList(head);

	cout << "链表升序排序" << endl;
	sortList(head);
	printList(head);

	cout << "升序插入结点" << endl;
	insertPosSortList(head, 8);
	printList(head);

	cout << "翻转链表" << endl;
	reverseList(head);
	printList(head);

	clearList(head);

	system("pause");
	return 0;
}
*/