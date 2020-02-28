#include<stdio.h>
#include<string.h>
int count = 0, can[8][8];
int notdanger1(int row, int j, int(*chess)[8], int n)
{
	int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,i,k;
	for ( i = 0; i < n; i++)     //line 
	{
		if (chess[i][j] ==1)
		{
			flag1 = 1;
			break;
		}
	}
	for ( i = row,k=j; i >= 0&&k>=0; i--, k--)
	{
		if (chess[i][k] == 1)
		{
			flag2 = 1;
			break;
		}
	}
	for ( i = row, k = j; i < n&&k<n; i++,k++)
	{
		if (chess[i][k] == 1)
		{
			flag3 = 1;
			break;
		}
	}
	for ( i = row, k = j; i >= 0&&k<n; i--,k++)
	{
		if (chess[i][k] == 1)
		{
			flag4 = 1;
			break;
		}
		
	}
	for ( i = row, k = j; i < n&&k>=0; i++,k--)
	{
		if (chess[i][k] == 1)
		{
			flag5 = 1;
			break;
		}
	}
	if (flag1 || flag2 || flag3 || flag4 || flag5)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int n2danger2(int row, int j, int(*chess)[8], int n)
{
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0,i,k;
	for ( i = 0; i < n; i++)     //line 
	{
		if (chess[i][j] == 2)
		{
			flag1 = 1;
			break;
		}
	}
	for ( i = row, k = j; i >= 0 && k >= 0; i--, k--)
	{
		if (chess[i][k] == 2)
		{
			flag2 = 1;
			break;
		}
	}
	for ( i = row, k = j; i < n && k < n; i++, k++)
	{
		if (chess[i][k] == 2)
		{
			flag3 = 1;
			break;
		}
	}
	for (i = row, k = j; i >= 0 && k < n; i--, k++)
	{
		if (chess[i][k] == 2)
		{
			flag4 = 1;
			break;
		}

	}
	for ( i = row, k = j; i < n && k>=0; i++, k--)
	{
		if (chess[i][k] == 2)
		{
			flag5 = 1;
			break;
		}
	}
	if (flag1 || flag2 || flag3 || flag4 || flag5)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void n2_bqueen(int row, int line, int(*chess)[8], int n)
{
	int chess2[8][8] = { 0 }, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}
	if (row == n)
	{
		count++;
	}
	else
	{
		for (j = 0; j < line; j++)                  
		{
			if (n2danger2(row, j, chess2, n) && can[row][j] != 0&&chess2[row][j]!=1)
			{
				for ( i = 0; i < n; i++)
				{
					if(chess2[row][i]!=1)
						chess2[row][i] = 0;
				}
				chess2[row][j] = 2;
				n2_bqueen(row + 1, line, chess2, n);
			}
		}
	}
}
void n2_Wqueen(int row,int line ,int (*chess)[8],int n)
{
	int chess2[8][8] = {0}, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}
	if (row == n)
	{
		n2_bqueen(0, n, chess2, n);
	}
	else
	{
		for (j = 0; j < line; j++)                     //白棋
		{
			if (notdanger1(row,j,chess2,n)&&can[row][j]!=0) 
			{
				for ( i = 0; i < n; i++)
				{
					chess2[row][i] = 0;
				}
				chess2[row][j] = 1;
				n2_Wqueen(row + 1, line, chess2, n);
			}
		}
	}
}

int main()
{
	int chess[8][8];
	int n,i,j;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf_s("%d", &can[i][j]);
	n2_Wqueen(0, n, chess, n);
	printf("%d", count);
	return 0;
}
