//traversal linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	
};
struct node *s;
struct node* count_nodes(struct node*s);
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
	struct node* count_nodes(struct node*s);
	{
		int count=0;
		if(s==NULL)
		{
			printf("linked list is empty");
		}
		struct node*r;
		r=s;
		while(r!=NULL)
			{
				count++;
				r=r->next;
			}
			printf("total number of elements=\n");
			printf("%d\n",count);
		}
	printf("linked list is:\n");
	while(s!=NULL)
	{
		printf("%d\n",s->data);
		s=s->next;
	}
	struct node* count_nodes(struct node*s);
	getch();
	}

