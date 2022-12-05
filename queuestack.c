#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack1[5],stack2[5];
int top1=-1,top2=-1;
int count=0;
void push1(int data)
{
	if(top1==N-1)
	printf("\nOverflow\n");
	else
	{
		top1++;
		stack1[top1]=data;
	}
}
int pop1()
{
	if(top1==-1)
	printf("\nEmpty Queue\n");
	else
	{
		int a=stack1[top1];
		top1--;
		return a;
	}
}
void push2(int x)
{
	if(top2==N-1)
	printf("\nOverflow\n");
	else
	{
		top2++;
		stack2[top2]=x;
	}
}
int pop2()
{
	if(top2==-1)
	printf("\nEmpty queue\n");
	else
	{
		int a=stack2[top2];
		top2--;
		return a;
	}
}
void enqueue(int x)
{
	push1(x);
	count++;
}
void dequeue()
{
	if((top1==-1) && (top2==-1))
	printf("\nEmpty Queue\n");
	else
	{
	int i;
	for(i=0;i<count;i++)
	{
		int element=pop1();
		push2(element);
	}
	int b=pop2();
	printf("\nThe dequeued element is %d\n",b);
	count--;
	for(i=0;i<count;i++)
	{
		int c=pop2();
		push1(c);
	}
    }
}
void display()  
{ 
   int i; 
   for(i=0;i<=top1;i++)  
  {  
     printf("%d   ", stack1[i]);  
  }  
}
void main()
{
	int choice,data;
	do
	{
		printf("\nEnter 0 to exit\nEnter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to display: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("\nProgram Terminated\n");
		        exit(0);
		        break;
		    case 1:
		    	printf("\nEnter data:");
		    	scanf("%d",&data);
		    	enqueue(data);
		    	break;
		    case 2:
		    	dequeue();
		    	break;
		    case 3:
		    	display();
		    	break;
		    default:
		    	printf("\nEnter Valid choice!!\n");
    	}
	}while(choice!=0);
}
 
