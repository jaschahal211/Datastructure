#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	
};
struct node *s;
void main()
{
	struct node*p,*q;
	char ch;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter the value of first node\n");
	scanf("%d",&p->data);
	s=p;
	do
	{
		q=(struct node*)malloc(sizeof(struct node));
		printf("enter the value of next node\n");
		scanf("%d",&q->data);
		p->next=q;
		p=q;
		printf("press y for more node\n");
		ch=getch();
	}while(ch=='y'||ch=='Y');
	p->next=NULL;
	while(s!=NULL)
	{
		printf("%d\n",s->data);
		s=s->next;
	}
	getch();
	}

