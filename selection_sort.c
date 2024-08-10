//selection search
#include<stdio.h>
void main()
{
	int i,j,a[10],n,min,temp;
	printf("enter no of elements you want=\n");
	scanf("%d",&n);
	printf("enter array elements=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	
}
		printf("sorted array is:\n");
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i]);
		}
	
}
