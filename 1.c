#include<stdio.h>
#define MAXSIZE 100
int sjz(int x,int yjz);
int *zh(int s,int xjz);
int b =0;
int main()
{
	int yjz,xjz,x,s,*ch;
	printf("please input yjz\n");
	scanf("%d",&yjz);
	printf("please input xianjinzhi\n");
	scanf("%d",&xjz);
	printf("please input shux\n");
	scanf("%d",&x);
	s = sjz(x,yjz);
	ch = zh(s,xjz);
	for(b;b>=0;b--)
		printf("%d",ch[b]);



}
int sjz(int x,int yjz)
{
	int s = 0,d = 1;
	while(x)
	{
		s = s + x%10*d;
		x = x/10;
		d = d*yjz;
	}
	return s;
}
int *zh(int s ,int xjz)
{
	int a[MAXSIZE],*c;
	c = a;
	while(s)
	{
		a[b]=s%xjz;
		s = s/xjz;
		b++;
	}
	b--;
	return c;
}

