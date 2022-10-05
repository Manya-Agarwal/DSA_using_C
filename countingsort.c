#include<stdio.h>
int main()
{
	int n=8;
	int B[10];
	int A[]={2,3,5,1,4,0,2,1};
	int C[10];
	int i,j,max;
	max=A[0];
	for(i=0;i<n;i++)
	{
		C[i]=0;
		if (max<A[i])
		{
			max=A[i];
		}
	}
	for(j=0;j<n;j++)
	{
		C[A[j]]=C[A[j]]+1;
	}
	for(i=1;i<=max;i++)
	{
		C[i]=C[i]+C[i-1];
	}
	for(j=n-1;j>=0;j--)
	{
		B[C[A[j]]]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",B[i]);
	}
}
