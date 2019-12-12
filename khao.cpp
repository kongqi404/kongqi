#include<stdio.h>
#include<math.h>
int main()
{
	int l, k, a[100][100] = {0};
	long long int s = 0;
	scanf_s("%d %d", &k, &l);
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i == 0 && j == 0)
				a[i][j] = 0;
			else if (i == 0)
				a[i][j] = 1;
			else
				for (int m = 0; m < k; m++)
					if (abs(j - m) != 1)
						a[i][j] = a[i][j] + a[i - 1][m];
		}
	}
	for (int i = 0; i < k; i++)
		s = s + a[l-1][i];
	printf("%d", s%1000000007);
	return 0;
}