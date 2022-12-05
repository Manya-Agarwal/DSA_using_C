#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*next;	
};
struct node*front=NULL;
struct node*rear=NULL;
int n;
void enqueue()
{
	if(n!=0)
	{
		int x;
		printf("Enter the element which is to be inserted");  
        scanf("%d", &x);
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(front==NULL && rear==NULL)
	{
		front=rear=newnode;
		newnode->next=front;
	}
	else
	{
		newnode->next=front;
		rear->next=newnode;
		rear=newnode;
	}
	n--;
    }
    else
    printf("\nQueue has reached its maximum limit\n");
}
void dequeue()
{
	struct node*temp;
	if(front==NULL && rear==NULL)
	printf("\nUNDERFLOW\n");
	else if(front==rear)
	{
		temp=front;
		front=rear=NULL;
		n++;
	}
	else
	{
		temp=front;
		front=front->next;
		rear->next=front;
		n++;
	}
	free(temp);
}
void display()
{
	struct node*temp;
	temp=front;
	if(front==NULL && rear==NULL)
	printf("\nEmpty list\n");
	else
	{
		while(temp->next!=front)
		{
			printf("%d,",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
void peek()
{
	if(front==NULL && rear==NULL)
	printf("\nQueue is empty\n");
	else
	printf("\nThe element at front is %d\n",front->data);
}
void isfull(int n1)
{
	int N=length();
	if(n1==N)
	printf("\nQueue is full\n");
	else
	printf("\nQueue is not full\n");
}
void isempty(int n1)
{
	int N=length();
	if(n1!=N)
	printf("\nQueue is empty\n");
	else
	printf("\nQueue is not empty\n");
}
int length()
{
	int count=0;
	if(front==NULL && rear==NULL)
	{
		return count;
	}
	else
	{
		struct node*temp;
		temp=front;
		count=1;
		while(temp->next!=front)
		{
			count++;
			temp=temp->next;
		}
		return count;
	}
}
int main()  
{  
    int choice;     
    printf("\nEnter how many nodes you want to enter\n");
	scanf("%d",&n);
	int n1=n;  
    do     
    {
	printf("\n\nPress 0: To exit");  
    printf("\nPress 1: Enqueue an element");  
    printf("\nPress 2: Dequeue an element");  
    printf("\nPress 3: Display the element"); 
	printf("\nPress 4: To peek an element");
	printf("\nPress 5: To check if the queue is full");
	printf("\nPress 6: To check if the queue is empty"); 
    printf("\nEnter your choice");  
    scanf("%d", &choice);  
      
    switch(choice)  
    { 
	    case 0:
	    	printf("\nProgram Terminated\n");
	    	exit(0);
	    	break;
          
        case 1:  
        enqueue(); 
        break;  
        case 2:  
        dequeue();  
        break;  
        case 3:  
        display();
        break;
        case 4:
        peek();
        break;
        case 5:
        isfull(n1);
        break;
        case 6:
        	isempty(n1);
        	break;
		default:
		printf("\nEnter invalid choice!!!\n"); 
  
    }
	}while(choice!=0); 
    return 0;  
} 


