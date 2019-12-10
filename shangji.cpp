#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
int main()
{
	char *zhan[201]; 
	int top = 0, down = 0;
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m = i % 2;
		char s;
		if (m == 0)
			s = '+';
		else
			s = '-';
		char c = i+48;
		char *a;
		char b[1] = { c };
		if (i == 0)
		{
			zhan[i] = (char*)malloc(sizeof("sin(i)"+1));
			a = (char*)malloc(sizeof("sin(i)"));
		}
		else
		{
			zhan[i] = (char*)malloc(sizeof("sin(i+" + strlen(zhan[i - 1])+1));
			a = (char*)malloc(sizeof("sin(i+" + strlen(zhan[i - 1])+1));
		}
		if (i == 0)
		{
			strcpy_s(a, sizeof(a), "sin(");
			strcat_s(a, sizeof(a), b);
			strcpy_s(zhan[i], sizeof(a), a);
		}
		else
		{
			strcpy_s(a, sizeof(a), &s);
			strcat_s(a, sizeof(a), "sin(");
			strcat_s(a, sizeof(a), b);
			strcpy_s(zhan[i], sizeof(a), a);

		}
		free(a);
		printf_s("%s", zhan[i]);
	}
}