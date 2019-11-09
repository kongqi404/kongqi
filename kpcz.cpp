#include<stdio.h>
int main()
{
	int cz(int* p, int start, int end, int k);
	int a[200], start, end,n,k;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	scanf_s("%d %d %d", &start, &end,&k);
	printf("%d", cz(a, start-1, end-1, k-1));
}
int cz(int* p, int start, int end,int k)
{
	int r = p[end];
	int i = start;
	if (i == k)
		return p[i];
	for (int j = start; j <= end; j++)
	{
		if (p[j] <= r)
		{
			p[j] = p[j] ^ p[i];
			p[i] = p[j] ^ p[i];
			p[j] = p[j] ^ p[i];
			i++;
		}
	}
	i--;
	if (i < k)
		cz(p, i+1, end, k);
	else
		cz(p, start, i-1, k);
		
}