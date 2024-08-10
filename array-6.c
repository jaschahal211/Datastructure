//insert
#include<stdio.h>
void main()
{
	int a[100],n,i,j,item,index;
	printf("enter number of elements you want in array=\n");
	scanf("%d",&n);
	printf("enter array element=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
}
		printf("enter the index where you want to insert the element=\n");
		scanf("%d",&index);
		printf("enter the element you want to insert=\n");
		scanf("%d",&item);
		for(i=n;i>=index;i--)
		{
			a[i+1]=a[i];
			
		}
		a[index]=item;
		n=n+1;
		
	
	printf("new array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

