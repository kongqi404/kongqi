#include<stdio.h>
#include<malloc.h>
typedef struct jh
{
	int data;
	struct jh* next;
}J,*JH;
int m = 0;
int main()
{
	int n, k, a[10000];
	scanf_s("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (int i = 0; i < n; i++)
		if (a[i] % k == 0)
			m++;
	JH head = (JH)malloc(sizeof(J));
	JH temp,lb = head;
	for (int i = 0; i < n; i++)
	{
		temp = (JH)malloc(sizeof(J));
		temp->data = a[i];
		lb->next = temp;
		lb = lb->next;
	}
	int i = 1;
	
	while (i != n)
	{
		temp = head->next;
		for (int j = i ; j < n; j++)
		{
			temp->data += a[j];
			if (temp->data % k == 0)
				m++;
			temp = temp->next;
		}
		i++;
	}
	printf("%d", m);
	return 0;
	
}