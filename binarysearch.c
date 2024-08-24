#include<stdio.h>
void main()
{
	int low,high,found=0,mid,item,n,a[10],i;
	printf("enter the number of elements you want in array=\n");
	scanf("%d",&n);
	printf("enter array elements=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element you want to search=\n");
	scanf("%d",&item);
	low=0;
	high=n+1;
	mid=(low+high)/2;
	for(i=0;i<n;i++)
	{
	
	if(a[i]==item)
	{
		found=1;
		printf("%d item found at %d position",item,mid+1);
	}
	if(item<a[mid])
    {
	low=mid+1;
	}	
	if(item>a[mid])
	{
		high=mid-1;
	}
	mid=(low+high)/2;
}
if(found==0)
{
	printf("item not found");
}
	
}
