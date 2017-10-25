#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
//��̬�������
typedef struct stu {
	int id;
	char name[50];
	char *next;
}stu;

int main()
{
	stu s1 = { 1, "allen", NULL };
	stu s2 = { 2, "kobe", NULL };
	stu s3 = { 3, "yao", NULL };

	s1.next = &s2; //s1��nextָ��s2
	s2.next = &s3;
	s3.next = NULL; //β�ڵ�

	stu *p = &s1;

	while (p != NULL)
	{
		printf("id:%d, name:%s\n", p->id, p->name);

		//�ڵ�������һλ
		p = p->next;
	}

	system("pause");
	return 0;
}
*/




/*
typedef struct Node {
	int id;
	struct Node *next; //ָ����
}Node;

//����ͷ�ڵ�
//�����ͷ�ڵ��ַ�ɺ���ֵ����
Node *SListCreate()
{
	Node *head = NULL;

	//ͷ�����Ϊ��־�����洢��Ч����
	head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	//��head��Ա��ֵ
	head->id = -1;
	head->next = NULL;

	Node *pCur = head;
	Node *pNew = NULL;

	int data;
	while (1)
	{
		printf("���������ݣ�");
		scanf("%d", &data);

		if (data == -1)//�˳�
		{
			break;
		}

		//�½ڵ㶯̬����ռ�
		pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			continue;
		}

		//��pNew��Ա��ֵ
		pNew->id = data;
		pNew->next = NULL;

		//��ǰ����nextָ��pNew
		pCur->next = pNew;

		//pNew��һ���ڵ�ָ��NULL
		pNew->next = NULL;

		//��pCur�ƶ���pNew��pCurָ��pNew
		pCur = pNew;
	}

	return head;
}

//�������
int SListPrint(Node *head)
{
	if (head == NULL)
	{
		return -1;
	}

	//ȡ����һ����Ч�ڵ㣨ͷ���next��
	Node *pCur = head->next;

	printf("head ->");
	while (pCur != NULL)
	{
		printf("%d-> ", pCur->id);

		//��ǰ�ڵ������ƶ�һλ��pCurָ����һ��
		pCur = pCur->next;
	}
	printf("\n");

	return 0;
}

//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣬��ֵΪy�Ľ�㲻���ڣ�����ڱ�β
int SListNodeInsert(Node *head, int x, int y)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id == x)//�ҵ�ƥ����
		{
			break;
		}

		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next;//pCurָ����һ�����
	}

	//2�����
	//1����ƥ��Ľ�㣬pCurΪƥ���㣬pPreΪpCur����һ�����
	//2��û���ҵ�ƥ��Ľ�㣬pCurΪ�ս�㣬pPreΪ���һ�����

	//���½�㶯̬����ռ�
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}

	//��pNew��Ա��ֵ
	pNew->id = y;
	pNew->next = NULL;

	//����ָ��λ��
	pPre->next = pNew;//pPre��һ��ָ��pNew
	pNew->next = pCur;//pNew��һ��ָ��pCur

	return 0;
}

//ɾ�����
int SListNodeDel(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0;//0��ʾû�д˽�㣬1��ʾ�ҵ��˽��

	while (pCur != NULL)
	{
		if (pCur->id == x)//�ҵ�ƥ����
		{
			//pPre����һ��ָ��pCur����һ�����
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;

			break;
		}

		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next;//pCurָ����һ�����
	}

	if (flag == 0)
	{
		printf("û���ҵ����Ϊ%d\n", x);
		return -2;
	}

	return 0;
}

//ɾ�����н��
int SListNodeDelPro(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0;//0��ʾû�д˽�㣬1��ʾ�ҵ��˽��

	while (pCur != NULL)
	{
		if (pCur->id == x)//�ҵ�ƥ����
		{
			//pPre����һ��ָ��pCur����һ�����
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			//���¸�pCurָ����һ�����
			pCur = pPre->next;

			flag = 1;

			//break;
			continue;
		}

		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next;//pCurָ����һ�����
	}

	if (flag == 0)
	{
		printf("û���ҵ����Ϊ%d\n", x);
		return -2;
	}

	return 0;
}

//�������
int SListNodeDestroy(Node *head)
{
	if (head == NULL)
	{
		return -1;
	}

	Node *tmp;
	int i = 0;
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		//headָ��tmp
		head = tmp;

		i++;
	}
	printf("�ͷŽ�������%d\n", i);

	return 0;
}

//��������
int SListNodeSort(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return -1;
	}

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node tmp;

	//pPre->next != NULL����������2�����
	for (pPre = head->next; pPre->next != NULL; pPre = pPre->next)
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			//ע�⣬���������������Ҫ������ָ����Ҳ��Ҫ����
			if (pPre->id > pCur->id)//����
			{
				//ֻ����������
				tmp.id = pCur->id;
				pCur->id = pPre->id;
				pPre->id = tmp.id;
#if 0
				//����������
				tmp = *pCur;
				*pCur = *pPre;
				*pPre = tmp;

				//����ָ������Ҫ��
				tmp.next = pCur->next;
				pCur->next = pPre->next;
				pPre->next = tmp.next;
#endif
			}
		}
	}

	return 0;
}

//���������
int SListNodeInsertPro(Node *head, int x)
{
	int ret = SListNodeSort(head);
	if (ret != 0)
	{
		return ret;
	}

	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id > x)//�ҵ�ƥ����
		{
			break;
		}

		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next;//pCurָ����һ�����
	}

	//2�����
	//1����ƥ��Ľ�㣬pCurΪƥ���㣬pPreΪpCur����һ�����
	//2��û���ҵ�ƥ��Ľ�㣬pCurΪ�ս�㣬pPreΪ���һ�����

	//���½�㶯̬����ռ�
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}

	//��pNew��Ա��ֵ
	pNew->id = x;
	pNew->next = NULL;

	//����ָ��λ��
	pPre->next = pNew;//pPre��һ��ָ��pNew
	pNew->next = pCur;//pNew��һ��ָ��pCur

	return 0;

}

//��ת�����������ָ�򷴹���
int SListNodeReverse(Node *head)
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return -1;
	}

	Node *pPre = head->next;
	Node *pCur = pPre->next;
	pPre->next = NULL;
	Node *tmp = NULL;

	while (pCur != NULL)
	{
		tmp = pCur->next;
		pCur->next = pPre;

		pPre = pCur;
		pCur = tmp;
	}

	//head->next->next = NULL;
	head->next = pPre;

	return 0;
}

int main()
{
	Node *head = NULL;

	head = SListCreate();
	SListPrint(head);

	printf("�ڽ��5ǰ�����4���\n");
	SListNodeInsert(head, 5, 4);
	SListPrint(head);

	//printf("ɾ�����Ϊ5��\n");
	//SListNodeDel(head, 5);
	printf("ɾ�����н��Ϊ5��\n");
	SListNodeDelPro(head, 5);
	SListPrint(head);


	printf("�����\n");
	SListNodeSort(head);
	SListPrint(head);

	printf("���������7��\n");
	SListNodeInsertPro(head, 7);
	SListPrint(head);

	SListNodeReverse(head);
	printf("����ת\n");
	SListPrint(head);

	SListNodeDestroy(head);

	system("pause");
	return 0;
}
*/