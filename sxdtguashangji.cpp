#include<stdio.h>
#include<malloc.h>
typedef struct ljlb
{
	int data;
	ljlb* next;
}ljb;
typedef struct ljsz
{
	int jd;
	int yes;
	int no;
	ljb* right;
}ljz;
int cz(ljz* a, int b,int n)
{
	for (int i = 0; i < n; i++)
		if (a[i].jd==b)
		{
			return i;
		}
	return 0;
}
void creat(ljz* a, int fq, int ez,int n)
{
	int i = cz(a, fq,n);
	if (a[i].right == NULL)
	{
		ljb* b = (ljb*)malloc(sizeof(ljb));
		b->data = ez;
		b->next = NULL;
		a[i].right = b;
	}
	else
	{
		ljb* b = a[i].right;
		while (b->next)
		{
			b = b->next;
		}
		ljb* p = (ljb*)malloc(sizeof(ljb));
		p->data = ez;
		p->next = NULL;
		b->next = p;
	}
}
void dt(ljz*(* a),int n)
{
	ljb* p = (*a)->right;
	(*a)->yes = (*a)->jd;
	(*a)->no = 0;
	while (p)
	{
		int i = cz(*a, p->data,n);
		dt(&a[i],n);
		(*a)->yes = (*a)->yes + a[cz(*a, p->data,n)]->no;
		(*a)->no = (*a)->no + (a[cz(*a, p->data,n)]->yes < a[cz(*a, p->data,n)]->no ? a[cz(*a, p->data,n)]->no : a[cz(*a, p->data,n)]->yes);
		p = p->next;
	}

}
int main()
{
	ljz a[10];
	for (int i = 0; i <10; i++)
		a[i].right = NULL;
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i].jd);
	for (int i = 0; i < n - 1; i++)
	{
		int fq, ez;
		scanf_s("%d %d", &fq, &ez);
		creat(a, fq, ez, n);
	}
	ljz* b = &a[0];
	dt(&b, n);
	printf("%d", a[0].yes < a[0].no ? a[0].no : a[0].yes);

}
