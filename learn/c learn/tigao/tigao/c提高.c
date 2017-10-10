#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
//—°‘Ò∑®≈≈–Ú
int main()
{
	char a[] = {6,2,4,9,4,5,8,7,1,0,10};
	char tmp;
	int i, j;
	int n = sizeof(a) / sizeof(a[0]);
	printf("before\n");
	for (i = 0; i < n; i++)
	{
		printf("%d,", a[i]);
	}
	printf("\nafter\n");
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d,", a[i]);
	}

	system("pause");
	return 0;
}
*/