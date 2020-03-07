#include<stdio.h>
#include<malloc.h>
#include<string.h>
int s=0;
int main()
{
	void bd(int i, int k, int cache[20], int flag);
	int k;
	scanf("%d", &k);
	

	for (int i = 1; i <= k; i++)
	{
		int cache[20] = { 0 };
		bd(i, k, cache, 0);
	}
	printf("%d", s);
}
void bd(int i, int k,int cache[20],int flag)
{
	if (flag == k)
		return;
	int cache1[20] = {0};
	for (int j = 0; j < flag; j++)
		cache1[j] = cache[j];
	cache1[flag] = i;
	if (flag == 0 || flag == 1)
	{
		if (flag == 1)
			s++;
		for (int j = 1; j <= k; j++)
		{
			int flag1 = 1;
			for(int k=0;k<=flag;k++)
				if (j == cache1[k])
				{
					flag1 = 0;
					break;
				}
			if (flag1 != 0)
				bd(j, k, cache1, flag + 1);
		}
	}
	else
	{
		
		if (((cache1[flag - 1] > cache1[flag - 2]) && (cache1[flag] < cache1[flag - 2])) || ((cache1[flag - 1] < cache1[flag - 2]) && (cache1[flag] > cache1[flag - 2])))
		{
			s++;
			for (int j = 1; j <= k; j++)
			{
				int flag1 = 1;
				for (int k = 0; k <= flag; k++)
					if (j == cache1[k])
					{
						flag1 = 0;
						break;
					}
				if (flag1 != 0)
					bd(j, k, cache1, flag + 1);
			}
		}
		else
			return;
	}
}
