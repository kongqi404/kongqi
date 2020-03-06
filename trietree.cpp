#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAXSIZE 26
typedef struct trietree
{
	int flag;
	trietree* next[MAXSIZE];
}trie;
trie* creatnode()
{
	trie* p = (trie*)malloc(sizeof(trie));
	p->flag = 1;
	for (int i = 0; i < MAXSIZE; i++)
		p->next[i] = NULL;
	return p;
}
void insertnode(trie *root,char* s,int i)
{
	if (i == strlen(s))
	{
		root->flag = 0;
		return;
	}
	if (root->next[s[i] - 'a'] == NULL)
	{
		trie* p = creatnode();
		root->next[s[i] - 'a'] = p;
		
		insertnode(p, s, i + 1);
	}
	else
	{
		
		insertnode(root->next[s[i] - 'a'], s, i + 1);
	}
}
int search(trie* root, char* s, int i)
{
	if(i==strlen(s)&&root->flag==0)
		return 1;
	if (root->next[s[i] - 'a'] != NULL)
		return search(root->next[s[i] - 'a'], s, i + 1);
	else
		return 0;
}
int main()
{
	trie* root = creatnode();
	int n;
	char s[100];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", &s, 100);
		insertnode(root, s, 0);
	}
	scanf_s("%s", &s, 100);
	printf("%d", search(root, s, 0));
}
