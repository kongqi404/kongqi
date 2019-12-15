#include<stdio.h>
#include<math.h>
int partion(int* a, int p, int r)
{
	int x = a[r];
	int i = p - 1;
	int temp;
	for (int j = p; j < r; j++)
	{
		if (a[j] < x)
		{
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp= a[i + 1];
	a[i+1] = a[r];
	a[r] = temp;
	return i + 1;
}
void qs(int* a, int p, int r)
{
	if (p < r)
	{
		int q = partion(a, p, r);
		qs(a, p, q - 1);
		qs(a, q + 1, r);
	}
}
int main()
{
	int a[] = { 1,7,6,4,2 };
	qs(a, 0, 4);
	printf("%d", a[2]);
}
