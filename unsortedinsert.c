#include<stdio.h>
int unsortedinsert(int a[],int n, int key, int capacity,int index)
{
	int i;
    for(i=n-1;i>=0;i--)
    {
    	if(i>=index)
    	a[i+1]=a[i];
    	else
    	break;
	}
	a[i+1]=key;
	return 0;
}
int main()
{
	int a[]={9,7,10,6,11};
	int key,n,pos,capacity=10,j;
	n=sizeof(a)/sizeof(a[0]);
	printf("enter the key\n");
	scanf("%d",&key);
	printf("\nenter the position\n");
	scanf("%d",&pos);
	int index=pos-1;
	unsortedinsert(a, n,key,capacity,index);
	printf("Array after insertion \n\n");
	for(j=0;j<n+1;j++)
		printf("  %d",a[j]);
	
	return 0;
}
