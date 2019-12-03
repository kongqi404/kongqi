#include<stdio.h>
int main()
{
	int a[35] = { 0 },top=0,down =0, i, j, n, b;
	scanf_s("%d", &n);
	for (i = 0; i < n+1; i++)
	{
		if (i == 0)
		{
			a[top] = 1;
			top++; top = top % 35;
		}
		else
		{
			for (j = 0; j <= i; j++)
			{
				if (j == 0 || j == i)
				{
					a[top] = 1;
					top++; top = top % 35;
				}
				else
				{
					a[top] = a[down] + b;
					top++;
					top = top % 35;
				}
				if (j != i)
				{
					b = a[down];
					printf("%d", a[down]);
					a[down] = 0;
					down++;
					down = down % 35;
					if (j != i - 1)
						printf(" ");
				}
			}
			if(i!=n)
				printf("\n");
		}
	}
}