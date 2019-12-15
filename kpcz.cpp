#include<stdio.h>
int main()
{
	int cz(int* p, int start, int end, int k);
	int a[1000], start[1000], end[1000], n, k[1000],m;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	scanf_s("%d", &m);
	for(int i =0;i<m;i++)
		scanf_s("%d %d %d", &start[i], &end[i], &k[i]);
	for (int i = 0; i < m; i++)
	{
		int b[1000];
		for (int j = 0; j < n; j++)
			b[j] = a[j];
		printf("%d\n", cz(b, start[i] - 1, end[i] - 1, start[i]-1+k[i] - 1));
	}
}
int cz(int* p, int start, int end, int k)
{
	int partion(int* a, int p, int r);
	int q = partion(p, start, end); 
	if (q == k)
		return p[q];
	else if (q < k)
		cz(p, q + 1, end, k);
	else
		cz(p, start, q - 1, k);
}
int partion(int* a, int p, int r)
{
	int x = a[r];
	int i = p - 1;
	int temp;
	for (int j = p; j < r; j++)
	{
		if (a[j] > x)
		{
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}
