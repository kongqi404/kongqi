#include<stdio.h>
#include<string.h>
#include<math.h>
#define XS 4
int main()
{
	void hashtable(char a[XS][100], int b, int hash[XS][2]);
	void cz(char* mz, int hash[XS][2], char a[XS][100]);
	char a[XS][100];
	int i = 0;
	for (i; i < XS; i++)
		scanf_s("%s", &a[i], 100);
	int hash[XS][2] = { {0} };
	hashtable(a, i, hash);
	printf("research\n");
	char mz[100];
	scanf_s("%s", &mz,100);
	cz(mz, hash, a);

}
int funct(char* a)
{
	int hashfunction;
	int s = 0;
	for (int j = 0; j < strlen(a); j++)
	{
		s = s + int(a[j]);
	}
	hashfunction =abs( int(XS * (s * 0.618 - int(s * 0.618))));
	return hashfunction;
}
void cz(char* mz, int hash[XS][2], char a[XS][100])
{
	int hashfunction = funct(mz);
	int h = hashfunction;
loop4:	if (hash[hashfunction][1] == 0)
loop5:printf("NONE");
else if (hash[hashfunction][1] == 1)
{
	int flag = 0;
	for (int i = 0; i < strlen(a[hash[hashfunction][0]]); i++)
		if (a[hash[hashfunction][0]][i] != mz[i])
		{
			flag = 1;
			break;
		}
	if (flag == 0)
		printf("yes");
	else
	{
		hashfunction = (hashfunction + 1) % XS;
		if(hashfunction!=h)
			goto loop4;
		else
			goto loop5;
	}
}
}
void hashtable(char a[XS][100],int b,int hash[XS][2])
{
	int  hashfunction;
	for (int i = 0; i < b; i++)
	{
		hashfunction = funct(a[i]);
loop3:		if (hash[hashfunction][1] == 0)
		{
			hash[hashfunction][0] = i;
			hash[hashfunction][1] = 1;
		}
		else
		{
			hashfunction = (hashfunction+1)%XS;
			goto loop3;
		}

	}
	
}
