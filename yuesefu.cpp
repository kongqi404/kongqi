#include<stdio.h>
#include<malloc.h>
typedef struct ysf
{
	int mm;
	struct ysf *next;
}ysf,*zz;  //��������
int main()
{
	zz csh();
	void jl(zz Head);  //��������
	int m;
	printf("���������m��ֵ(������):\n");
	scanf_s("%d", &m);
	while (m <= 0)
	{
		printf("��������������:(������)\n");
		scanf_s("%d", &m);
	}
	printf("������ÿ���˵�����(������)���س���������һ��������0����:\n");
	zz Head,r,l,z;
	Head = csh();   //��ʼ������
	jl(Head);  //��������
	r = Head;
	int i = 1;
	for (i; i <= m; i++)                            //Լɪ��ʵ��
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
			}                                      //����ѭ������ͷ�ڵ�
			l = z->next;
			z->next = z->next->next;
			m = l->mm;
			printf("����Ϊ:%d\n", m);
			free(l);
			i = 0;                                  //���¿�ʼѭ��
			if (Head->next == Head)
				break;                              //����Ϊ��ʱ����ѭ��
			continue;                               //��������ѭ�����迪ʼ��ѭ��
		}
		if (r->next != Head)                      //ѭ��
		{
			r = r->next;
		}
		else
		{
			r = r->next->next;
		}

	}

}
zz csh()  //��ʼ������
{
	zz Head;
	Head = (zz)malloc(sizeof(ysf));
	Head->next = NULL;
	return Head;
}
void jl(zz Head)   //ѭ��������
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
			printf("���벻��Ϊ����\n");
			printf("���¿�ʼ");
			main();

		}
	}
}
