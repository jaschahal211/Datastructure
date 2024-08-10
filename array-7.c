//del
#include<stdio.h>
void main()
{
	int a[100],n,i,item,index;
	printf("enter number of elements you want in array=\n");
	scanf("%d",&n);
	printf("enter array element=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
}
		printf("enter the index where you want to delete the element=\n");
		scanf("%d",&index);
		n=n-1;
		for(i=index;i<n;i++)
		{
			a[i]=a[i+1];
		
		}
		
		
	printf("new array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

