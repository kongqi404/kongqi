#include<stdio.h>
#include<malloc.h>
typedef struct ysf
{
	int mm;
	struct ysf *next;
}ysf,*zz;  //定义链表
int main()
{
	zz csh();
	void jl(zz Head);  //函数声明
	int m;
	printf("请输入初次m的值(正整数):\n");
	scanf_s("%d", &m);
	while (m <= 0)
	{
		printf("错误请重新输入:(正整数)\n");
		scanf_s("%d", &m);
	}
	printf("请输入每个人的密码(正整数)，回车键进行下一个，输入0结束:\n");
	zz Head,r,l,z;
	Head = csh();   //初始化链表
	jl(Head);  //插入链表
	r = Head;
	int i = 1;
	for (i; i <= m; i++)                            //约瑟夫环实现
	{
		if (i == m)
		{
			if (r->next != Head)
			{
				z = r;
			}
			else
			{
				z = r->next;
			}                                      //跳过循环链表头节点
			l = z->next;
			z->next = z->next->next;
			m = l->mm;
			printf("密码为:%d\n", m);
			free(l);
			i = 0;                                  //重新开始循环
			if (Head->next == Head)
				break;                              //链表为空时结束循环
			continue;                               //跳过下面循环步骤开始新循环
		}
		if (r->next != Head)                      //循换
		{
			r = r->next;
		}
		else
		{
			r = r->next->next;
		}

	}

}
zz csh()  //初始化链表
{
	zz Head;
	Head = (zz)malloc(sizeof(ysf));
	Head->next = NULL;
	return Head;
}
void jl(zz Head)   //循环链表建立
{
	int flag = 1;
	zz r;
	r = Head;
	while (flag)
	{
		int a;
		scanf_s("%d", &a);
		if (a > 0)
		{
			zz S;
			S = (zz)malloc(sizeof(ysf));
			S->mm = a;
			r->next = S;
			r = r->next;
		}
		else if(a == 0)
		{
			flag = 0;
			r->next = Head;
		}
		else
		{
			printf("密码不能为负！\n");
			printf("重新开始");
			main();

		}
	}
}
