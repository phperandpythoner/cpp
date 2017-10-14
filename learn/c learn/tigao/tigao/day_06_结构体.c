#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


struct Teacher1 {
	char name[50];
	int age;
};

typedef struct Teacher {
	char *name;
	int age;
}Teacher;

/*
int main01()
{
	int i = 0;

	struct Teacher1 t1[3] = { "xiaoming", 19, "xiaohong", 20, "xiaohua", 21 };
	int n = sizeof(t1) / sizeof(struct Teacher1);
	for (i = 0; i < n; i++)
	{
		printf("name:%s, age:%d\n", t1[i].name, t1[i].age);
	}
	printf("\n");

	//动态赋值
	char buf[30];
	for (i = 0; i < n; i++)
	{
		sprintf(buf, "name%d%d%d", i, i, i);
		strcpy(t1[i].name, buf);
	}
	for (i = 0; i < n; i++)
	{
		printf("name:%s, age:%d\n", t1[i].name, t1[i].age);
	}
	printf("\n");


	system("pause");
	return 0;
}
*/

/*
//结构体套一级指针1
int main02()
{
	Teacher t;
	t.name = (char *)malloc(30);
	strcpy(t.name, "allen");
	t.age = 20;
	printf("name:%s, age:%d\n", t.name, t.age);
	if (t.name != NULL)
	{
		free(t.name);
		t.name = NULL;
	}

	system("pause");
	return 0;
}

//结构体套一级指针2
int main03()
{
	Teacher *p;
	p = (Teacher *)malloc(sizeof(Teacher));
	if (p == NULL)
	{
		printf("error!");
		return -1;
	}
	p->name = (char *)malloc(30);
	strcpy(p->name, "xiaoxiao");
	p->age = 21;
	printf("name:%s, age:%d\n", p->name, p->age);
	if (p->name != NULL)
	{
		free(p->name);
		p->name = NULL;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	
	system("pause");
	return 0;
}

//结构体套一级指针3
int main04()
{
	Teacher *p = NULL;
	//Teacher p[3];
	p = (Teacher *)malloc(sizeof(Teacher) * 3);
	int i = 0;
	char buf[30];
	for (i = 0; i < 3; i++)
	{
		p[i].name = (char *)malloc(30);
		sprintf(buf, "name%d%d", i, i);
		strcpy(p[i].name, buf);
		p[i].age = 20 + i;
	}
	for (i = 0; i < 3; i++)
	{
		printf("name:%s, age:%d\n", p[i].name, p[i].age);
	}

	for (i = 0; i < 3; i++)
	{
		if (p[i].name != NULL)
		{
			free(p[i].name);
			p[i].name = NULL;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	system("pause");
	return 0;
}
*/

/*
//结构体做函数参数
void createTeacher(Teacher *p, int n)
{
	int i = 0;
	char buf[30];
	for (i = 0; i < n; i++)
	{
		p[i].name = (char *)malloc(30);
		sprintf(buf, "name%d%d", i, i);
		strcpy(p[i].name, buf);
		p[i].age = 20 + i;
	}
}
void showTeacher(Teacher *p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("name:%s, age:%d\n", p[i].name, p[i].age);
	}
}
void freeTeacher(Teacher *p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (p[i].name != NULL)
		{
			free(p[i].name);
			p[i].name = NULL;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}
int main()
{
	Teacher *p = NULL;
	//Teacher p[3];
	p = (Teacher *)malloc(sizeof(Teacher) * 3);
	int n = 3;

	createTeacher(p, n);

	showTeacher(p, n);

	freeTeacher(p, n);
	p = NULL;

	system("pause");
	return 0;
}
*/


//结构体嵌套二级指针
typedef struct Teacher2 {
	char **stu; //二维内存
}Teacher2;

/*
//结构体嵌套二级指针1
int main()
{

#if 0
	char **name = NULL;
	//char *name[3];
	int n = 3;
	int i = 0;
	char buf[30];
	name = (char **)malloc(sizeof(char *)*n);
	for (i = 0; i < n; i++)
	{
		name[i] = (char *)malloc(30);
		sprintf(buf, "name%d", i);
		strcpy(name[i], buf);
	}
	for (i = 0; i < n; i++)
	{
		printf("%s ", name[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (name[i] != NULL)
		{
			free(name[i]);
			name[i] = NULL;
		}
	}
	if (name != NULL)
	{
		free(name);
		name = NULL;
	}
#endif


	Teacher2 t;
	//t.stu[3]
	int n = 3, i = 0;
	char buf[30];
	t.stu = (char **)malloc(sizeof(char *) * n);
	for (i = 0; i < n; i++)
	{
		t.stu[i] = (char *)malloc(30);
		sprintf(buf, "name%d%d", i, i);
		strcpy(t.stu[i], buf);
	}
	for (i = 0; i < n; i++)
	{
		printf("name:%s ", t.stu[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (t.stu[i] != NULL)
		{
			free(t.stu[i]);
			t.stu[i] = NULL;
		}
	}
	if (t.stu != NULL)
	{
		free(t.stu);
		t.stu = NULL;
	}

	system("pause");
	return 0;
}
*/

/*
//结构体嵌套二级指针2
int main()
{
	Teacher2 *p = NULL;
	//p.stu[3]
	p = (Teacher2 *)malloc( sizeof(Teacher2));
	int n = 3, i = 0;
	char buf[30];
	p->stu = (char **)malloc(sizeof(char *) * n);
	for (i = 0; i < n; i++)
	{
		p->stu[i] = (char *)malloc(30);
		sprintf(buf, "name%d%d", i, i);
		strcpy(p->stu[i], buf);
	}
	for (i = 0; i < n; i++)
	{
		printf("name:%s ", p->stu[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (p->stu[i] != NULL)
		{
			free(p->stu[i]);
			p->stu[i] = NULL;
		}
	}
	if (p->stu != NULL)
	{
		free(p->stu);
		p->stu = NULL;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	system("pause");
	return 0;
}
*/

/*
//结构体嵌套二级指针3
int main()
{
	Teacher2 *p = NULL;
	//p[3].stu[3]
	int n = 3, i = 0, j = 0;
	char buf[30];
	p = (Teacher2 *)malloc(sizeof(Teacher2) * n); // p[3]
	for (i = 0; i < n; i++)
	{
		p[i].stu = (char **)malloc(sizeof(char *) * n);
		for (j = 0; j < n; j++)
		{
			p[i].stu[j] = (char *)malloc(30);
			sprintf(buf, "name%d%d%d%d", i, i, j, j);
			strcpy(p[i].stu[j], buf);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("name:%s ", p[i].stu[j]);
		}
		printf("\n");
	}
	printf("\n");


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (p[i].stu[j] != NULL)
			{
				free(p[i].stu[j]);
				p[i].stu[j] = NULL;
			}
		}
		if (p[i].stu != NULL)
		{
			free(p[i].stu);
			p[i].stu = NULL;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	
	system("pause");
	return 0;
}
*/