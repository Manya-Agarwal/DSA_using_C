#include<stdio.h>
void insert(int a[],int key,int n,int capacity)
{
	int i;
	if(n>=capacity)
	{
			printf("capacity full");
	}
	else 
	{
		for(i=n-1;i>=0;i--)
		{
			if(a[i]>key)
			{
				a[i+1]=a[i];
			}
			else
			break;
		}
		a[i+1]=key;
	
	}    

}
int main()
{
	int n,capacity,i,key,index;
	int a[]={1,2,3,5,6,7};
	n= sizeof(a)/sizeof(a[0]);
	capacity=10;
	printf("Array before insertion \n\n");
	for(i=0;i<n;i++)
	   printf("%d",a[i]);
    printf("\n\nenter key\n");
    scanf("%d",&key);
    insert(a,key,n,capacity);
    printf("Array after insertion \n\n");
	for(i=0;i<n+1;i++)
		printf("%d",a[i]);
		return 0;
}
