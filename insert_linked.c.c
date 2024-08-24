#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	
};
struct node *s;
struct node*insert_beg(struct node*s);
struct node*insert_end(struct node*s);
struct node*insert_after(struct node*s);
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
	//insert at beginning
	struct node*insert_beg(struct node*s);
{
    
	struct node*r;
	r=(struct node*)malloc(sizeof(struct node));
	printf("enter the data of new node at beginning=\n");
	scanf("%d",&r->data);
	r->next=s;
	s=r;
	}
	//insert_end
	struct node*insert_end(struct node*s);
	{
	struct node*r,*first;
	first=s;
	r=(struct node*)malloc(sizeof(struct node));
	printf("enter the data of next node at end=\n");
	scanf("%d",&r->data);
 while(s->next!=NULL)
	{
		s=s->next;
		}	
		s->next=r;
		r->next=NULL;
		s=first;
}
//insert at certain index
struct node*insert_after(struct node*s);
{
	struct node *r,*q,*first;
	int key;
	first=s;
	printf("enter element after which you want to insert element=\n");
	scanf("%d",&key);
	r=(struct node*)malloc(sizeof(struct node));
	printf("enter element you want to insert=\n");
	scanf("%d",&r->data);
	while(s->data!=key)
	{
		s=s->next;
	}
	if(s->data==key)
	{
		q=s->next;
		s->next=r;
		r->next=q;
		s=first;
	}
	else
	{
		printf("data not found\n");
	}
	
}
	struct node*insert_beg(struct node*s);
	struct node*insert_end(struct node*s);
	struct node*insert_after(struct node*s);
	printf("linked list is:\n");
	while(s!=NULL)
	{
		printf("%d\n",s->data);
		s=s->next;
	}
	getch();
	}

