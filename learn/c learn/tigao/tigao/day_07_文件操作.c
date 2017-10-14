#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
void file_fputc(char *path)
{
	FILE *fp = NULL;
	char str[] = "this is a test\n";
	int strLen = strlen(str);
	int i = 0;
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("file_fputc open");
		return;
	}
	for (i = 0; i < strLen; i++)
	{
		char ch = fputc(str[i], fp);
		printf("ch = %c\n", ch);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void file_fgetc(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("file_fgetc open");
		return;
	}

	while (!feof(fp))
	{
		char ch = fgetc(fp);
		printf("%c", ch);
	}
	printf("\n");
	

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void file_fputs(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");
	char *str[] = { "aaa\n", "bbb\n", "ccc" };
	int i = 0;
	int n = sizeof(str) / sizeof(str[0]);
	if (fp == NULL)
	{
		perror("file_fputs open");
		return;
	}

	for (i = 0; i < n; i++)
	{
		//成功返回0，失败返回非0
		fputs(str[i], fp);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void file_fgets(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");
	char buf[100];
	if (fp == NULL)
	{
		perror("file_fgets open");
		return;
	}

	while (!feof(fp))
	{
		fgets(buf, sizeof(buf), fp);
		printf("%s", buf);
	}
	printf("\n");

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void file_fwrite(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");
	char *str[] = { "aaaa\n", "bbbb\n", "cccc" };
	char buf[100] = {0};
	int i = 0;
	int n = sizeof(str) / sizeof(str[0]);
	if (fp == NULL)
	{
		perror("file_fwrite open");
		return;
	}

	for (i = 0; i < n; i++)
	{
		strcat(buf, str[i]);
	}
	fwrite(buf, strlen(buf), 1, fp);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void file_fread(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");
	char buf[100] = { 0 };
	if (fp == NULL)
	{
		perror("file_fread open");
		return;
	}
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	rewind(fp);

	fread(buf, 1, sizeof(buf), fp);
	printf("%s\n", buf);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void file_fprintf(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");
	char *str[] = { "aaaa\n", "bbbb\n", "cccc\n", "fprintf" };
	int i = 0;
	int n = sizeof(str) / sizeof(str[0]);
	if (fp == NULL)
	{
		perror("file_fprintf open");
		return;
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, str[i]);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void file_fscanf(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");
	char buf[100] = { 0 };
	if (fp == NULL)
	{
		perror("file_fscanf open");
		return;
	}
	char buf2[20] = { 0 };
	while (!feof(fp))
	{
		fscanf(fp, "%s", buf2);
		strcat(buf, buf2);
	}

	printf("%s", buf);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	char path[] = "../test.txt";

	//file_fputc(path);

	//file_fgetc(path);

	//file_fputs(path);

	//file_fgets(path);

	//file_fwrite(path);

	//file_fread(path);

	//file_fprintf(path);

	file_fscanf(path);

	system("pause");
	return 0;
}
*/