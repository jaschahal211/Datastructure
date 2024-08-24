#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	
};
struct node*delete_beg(struct node*s);
struct node*delete_end(struct node*s);
struct node*delete_after(struct node*s);
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
	//delete beginning
	struct node*delete_beg(struct node*s);
	{
		struct node *r;
		if(s==NULL)
		{
			printf("underflow");
			return;
		}
		r=s;
		s=r->next;
		free(r);
	}
	//delete end
	struct node*delete_end(struct node*s);
	{
		struct node *first,*r;
		first=s;
		while(s->next!=NULL)
		{
			r=s;
			s=s->next;
		}
		r->next=NULL;
		free(s);
		s=first;
	}
	//delete after the index
	struct node*delete_after(struct node*s);
	{
		struct node*first,*r;
		int key;
		first=s;
		printf("enter the key you want to del=\n");
		scanf("%d",&key);
		while(s->data!=key)
		{
			r=s;
			s=s->next;
		}
		r->next=s->next;
		free(s);
		s=first;
	}
	struct node*delete_beg(struct node*s);
	struct node*delete_end(struct node*s);
	struct node*delete_after(struct node*s);
	printf("linked list is:\n");
	while(s!=NULL)
	{
		printf("%d\n",s->data);
		s=s->next;
	}
	getch();
	}

