#include<stdio.h>
int main()
{
	int pd(int* a, int n, int* b);
	int s1_1[3], s1_2[2],s2_1[4],s2_2[4],s_end[5];
	int b[] = { 2,3,5,7 };
	for(int i=0;i<4;i++)
		for(int j =0;j<4;j++)
			for (int k = 0; k < 4; k++)        //暴力枚举第一个数
			{
				s1_1[0] = b[i];
				s1_1[1] = b[j];
				s1_1[2] = b[k];
				for(int l=0;l<4;l++)
					for (int m = 0; m < 4; m++)     //暴力枚举第二个数
					{
						s1_2[0] = b[l];
						s1_2[1] = b[m];
						int d = 0,d1=0;
						for (int i1 = 2; i1 >= 0; i1--)
						{
							s2_1[i1+1] = (s1_2[1]*s1_1[i1] + d) % 10;   //算出进位
							d = (s1_2[1]*s1_1[i1]+d) / 10;
							s2_2[i1+1] = (s1_2[0]*s1_1[i1] + d1) % 10;  
							d1 = (s1_2[0]*s1_1[i1] + d1) / 10;
						}
						s2_1[0] = d;
						if (pd(s2_1, 4, b) == 0)      //判断是否是2357
							continue;
						s2_2[0] = d;
						if (pd(s2_2, 4, b) == 0)  //同上
							continue;
						s_end[4] = s2_1[3];
						d = 0;
						s_end[3] = (s2_1[2] + s2_2[3] + d) % 10;     //计算最后结果
						d = (s2_1[2] + s2_2[3] + d) / 10;
						s_end[2] = (s2_1[1] + s2_2[2] + d) % 10;
						d = (s2_1[1] + s2_2[2] + d) / 10;
						s_end[1] = (s2_1[0] + s2_2[1] + d) % 10;
						d = (s2_1[0] + s2_2[1] + d) / 10;
						s_end[0] = s2_2[0] + d;
						if (pd(s_end, 5, b) == 1)                    //判断结果是否满足条件是则输出
						{
							printf("%d%d%d\n", s1_1[0], s1_1[1], s1_1[2]);
							printf("%d%d\n", s1_2[0], s1_2[1]);
							printf("%d%d%d%d\n", s2_1[0], s2_1[1], s2_1[2], s2_1[3]);
							printf("%d%d%d%d\n", s2_2[0], s2_2[1], s2_2[2], s2_2[3]);
							printf("%d%d%d%d%d\n", s_end[0], s_end[1], s_end[2], s_end[3], s_end[4]);
						}
					}
			}

}
int pd(int* a, int n, int* b)         //判断函数
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<4;j++) 
			if (a[i] == b[j])   //循环查找
			{
				flag = 1;
				break;
			}
		if (flag != 1)
			return 0;
		flag = 0;
	}
	return 1;
}
