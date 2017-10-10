#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
int main()
{
	char *restr = NULL; //通过strstr函数查找返回的位置
	char *str = "abcd1234abcd4567abcd9999";
	char *find_str = "abcd";
	char *replace_str = "dcba";
	int i = 0;
	char newstr[512] = { 0 };
	printf("strlen(str)=%d\n", strlen(str));
	printf("str position=%d\n", str);

	do
	{
		restr = strstr(str, find_str);
		printf("restr position=%d\n", restr);
		if (restr != NULL)
		{
			int len = 0;
			len = restr - str;
			if (len > 0)
			{
				strncat(newstr, str, len);
			}
			strncat(newstr, replace_str, strlen(replace_str));

			//重新设置起点位置
			str = restr + strlen(find_str);
			printf("reset str position=%d\n", str);
			printf("str = %s\n", str);
		}
		else
		{
			strcat(newstr, str);
			break;
		}
	} while (str != '\0');
	printf("%s\n", newstr);

	system("pause");
	return 0;
}
*/