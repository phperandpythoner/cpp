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

//����ͷ���
Node *createList()
{
	Node *head = NULL;
	head = new Node;

	if (head == NULL)
	{
		return NULL;
	}

	//��head��Ա��ֵ
	head->id = -1;
	head->next = NULL;

	//������ǰ�����½��
	Node *pcur = head;
	Node *pnew = NULL;

	int data;
	while (1)
	{
		cout << "���������ݣ�" << endl;
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

		//��ǰ����nextָ��pNew
		pcur->next = pnew;

		//��pCur�ƶ���pNew��pCurָ��pNew
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

	//ͷ��㲻��ӡ��ȡ����һ����Ч�ڵ㣨ͷ���next��
	Node *pcur = head->next;

	cout << "->" << endl;
	//����ʹ��pcur->next != NULL����Ϊ���һ������ָ����ָ�����NULL����������Ϊ�ж��������ٴ�ӡ��ĩβ���
	while (pcur != NULL)
	{
		cout << pcur->id << "->" << endl;

		pcur = pcur->next;
	}

	return 0;
}

//��ָ��x���λ�ò�����y
int insertPosList(Node *head, int x, int y)
{
	if (head == NULL)
	{
		return -1;
	}

	//����������㣬ppre��һ����㣬pcur��ǰ���
	Node *ppre = head;
	Node *pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id == x)
		{
			break;
		}

		//û���ҵ�ָ������Ľ�㣬��������ĩβ������
		ppre = pcur;
		pcur = pcur->next;
	}

	//����һ���½��
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

//ɾ��ָ�����x
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

		//pPreָ��pCurλ��,ִ����һ��ѭ������
		ppre = pcur;
		pcur = pcur->next;
	}

	return 0;
}

//ɾ��ָ�������н��
//����һ�����ָ��ǰ������һ�����ppre->next = pcur->next;
//���¸�pCurָ����һ����㣬pcur = ppre->next
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

//�������
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

	cout << "�ͷ���" << i << "�����" << endl;

	return 0;
}

//����
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
				//ֻ��������������
				tmp.id = pcur->id;
				pcur->id = ppre->id;
				ppre->id = tmp.id;
			}
		}
	}


	return 0;
}

//���������
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

	//����������㣬ppre��һ����㣬pcur��ǰ���
	Node *ppre = head;
	Node *pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id > x)
		{
			break;
		}

		//û���ҵ�ָ������Ľ�㣬��������ĩβ������
		ppre = pcur;
		pcur = pcur->next;
	}

	//����һ���½��
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

//��ת����
int reverseList(Node *head)
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return -1;
	}

	Node *ppre = head->next;
	Node *pcur = ppre->next;
	//��һ�����Ϊĩβ���
	ppre->next = NULL;
	Node *tmp = NULL;

	while (pcur != NULL)
	{
		//�ѵ�ǰ���pcur����һ����㿽����tmp
		tmp = pcur->next;
		//��ǰ�����ָ����һ�����ppre
		pcur->next = ppre;

		//���·���
		ppre = pcur;
		pcur = tmp;
	}

	//����ָ��ͷ��㣬ͷ���ָ��ǰ���ppre
	head->next = ppre;

	return 0;
}

int main()
{
	Node *head = NULL;
	head = createList();
	printList(head);

	cout << "��ָ�����5λ�ò�����4" << endl;
	insertPosList(head, 5, 4);
	printList(head);

	cout << "ɾ��ָ�����3" << endl;
	delPosList(head, 3);
	printList(head);

	cout << "ɾ��ָ�����9������" << endl;
	delPosProList(head, 9);
	printList(head);

	cout << "������������" << endl;
	sortList(head);
	printList(head);

	cout << "���������" << endl;
	insertPosSortList(head, 8);
	printList(head);

	cout << "��ת����" << endl;
	reverseList(head);
	printList(head);

	clearList(head);

	system("pause");
	return 0;
}
*/