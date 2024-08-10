//linear search
#include<stdio.h>
void main()
{
	int a[20],item,i,found=0,pos;
	printf("enter 10 elements you want=\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element you want to search=\n");
	scanf("%d",&item);
	for(i=0;i<=10;i++)
	{
		if(item==a[i])
		{
			found=1;
			pos=i;
			printf("%d found at %d position\n",item,pos+1);
			
		}
	}
	if(found==0)
	{
		printf("item not found");
	}
}
