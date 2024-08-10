//modifying element
#include<stdio.h>
void main()
{
	int a[100],i,j,n,item,found=0,pos=0,change,new_el;
	printf("enter the number of elements you want in array=\n");
	scanf("%d",&n);
	printf("enter array elements=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("how many elements you want to modify=\n");
	scanf("%d",&change);
    for(j=0;j<change;j++)
	{
		printf("enter elements you want to modify=\n");
	    scanf("%d",&item);
	for(i=0;i<n;i++)
	{
	    if(item==a[i])
		{
			
			found=1;
			pos=i;
			printf("item found at %d pos\n",pos+1);
			printf("enter the new element=\n");
			scanf("%d",&new_el);
			a[i]=new_el;
			printf("%d modified as %d\n",item,a[i]);
			
		}
	
	}
		if(found==0)
	{
		printf("the item you have entered is not in array list\n");
	}
	}
	
    printf("modified array:\n");
			for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	
	
}
