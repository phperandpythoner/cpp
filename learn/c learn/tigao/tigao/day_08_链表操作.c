#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
//静态链表操作
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

	s1.next = &s2; //s1的next指向s2
	s2.next = &s3;
	s3.next = NULL; //尾节点

	stu *p = &s1;

	while (p != NULL)
	{
		printf("id:%d, name:%s\n", p->id, p->name);

		//节点往后移一位
		p = p->next;
	}

	system("pause");
	return 0;
}
*/




typedef struct Node {
	int id;
	struct Node *next; //指针域
}Node;

//创建头节点
//链表的头节点地址由函数值返回
Node *SListCreate()
{
	Node *head = NULL;

	//头结点作为标志，不存储有效数据
	head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	//给head成员赋值
	head->id = -1;
	head->next = NULL;

	Node *pCur = head;
	Node *pNew = NULL;

	int data;
	while (1)
	{
		printf("请输入数据：");
		scanf("%d", &data);

		if (data == -1)//退出
		{
			break;
		}

		//新节点动态分配空间
		pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			continue;
		}

		//给pNew成员赋值
		pNew->id = data;
		pNew->next = NULL;

		//当前结点的next指向pNew
		pCur->next = pNew;

		//pNew下一个节点指向NULL
		pNew->next = NULL;

		//把pCur移动到pNew，pCur指向pNew
		pCur = pNew;
	}

	return head;
}

//链表遍历
int SListPrint(Node *head)
{
	if (head == NULL)
	{
		return -1;
	}

	//取出第一个有效节点（头结点next）
	Node *pCur = head->next;

	printf("head ->");
	while (pCur != NULL)
	{
		printf("%d-> ", pCur->id);

		//当前节点往下移动一位，pCur指向下一个
		pCur = pCur->next;
	}
	printf("\n");

	return 0;
}

//在值为x的结点前，插入值为y的结点，若值为y的结点不存在，则插在表尾
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
		if (pCur->id == x)//找到匹配结点
		{
			break;
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next;//pCur指向下一个结点
	}

	//2种情况
	//1、找匹配的结点，pCur为匹配结点，pPre为pCur的上一个结点
	//2、没有找到匹配的结点，pCur为空结点，pPre为最后一个结点

	//给新结点动态分配空间
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}

	//给pNew成员赋值
	pNew->id = y;
	pNew->next = NULL;

	//插入指定位置
	pPre->next = pNew;//pPre下一个指向pNew
	pNew->next = pCur;//pNew下一个指向pCur

	return 0;
}

//删除结点
int SListNodeDel(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0;//0表示没有此结点，1表示找到此结点

	while (pCur != NULL)
	{
		if (pCur->id == x)//找到匹配结点
		{
			//pPre的下一个指向pCur的下一个结点
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;

			break;
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next;//pCur指向下一个结点
	}

	if (flag == 0)
	{
		printf("没有找到结点为%d\n", x);
		return -2;
	}

	return 0;
}

//删除所有结点
int SListNodeDelPro(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0;//0表示没有此结点，1表示找到此结点

	while (pCur != NULL)
	{
		if (pCur->id == x)//找到匹配结点
		{
			//pPre的下一个指向pCur的下一个结点
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			//重新给pCur指向下一个结点
			pCur = pPre->next;

			flag = 1;

			//break;
			continue;
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next;//pCur指向下一个结点
	}

	if (flag == 0)
	{
		printf("没有找到结点为%d\n", x);
		return -2;
	}

	return 0;
}

//清空链表
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
		//head指向tmp
		head = tmp;

		i++;
	}
	printf("释放结点个数：%d\n", i);

	return 0;
}

//链表排序
int SListNodeSort(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return -1;
	}

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node tmp;

	//pPre->next != NULL，链表倒数第2个结点
	for (pPre = head->next; pPre->next != NULL; pPre = pPre->next)
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			//注意，排序除了数据域需要交换，指针域也需要交换
			if (pPre->id > pCur->id)//升序
			{
				//只交换数据域
				tmp.id = pCur->id;
				pCur->id = pPre->id;
				pPre->id = tmp.id;
#if 0
				//交换数据域
				tmp = *pCur;
				*pCur = *pPre;
				*pPre = tmp;

				//交换指针域（重要）
				tmp.next = pCur->next;
				pCur->next = pPre->next;
				pPre->next = tmp.next;
#endif
			}
		}
	}

	return 0;
}
int main()
{
	Node *head = NULL;

	head = SListCreate();
	SListPrint(head);

	printf("在结点5前面插入4结果\n");
	SListNodeInsert(head, 5, 4);
	SListPrint(head);

	//printf("删除结点为5的\n");
	//SListNodeDel(head, 5);
	printf("删除所有结点为5的\n");
	SListNodeDelPro(head, 5);
	SListPrint(head);


	printf("排序后\n");
	SListNodeSort(head);
	SListPrint(head);

	SListNodeDestroy(head);

	system("pause");
	return 0;
}
