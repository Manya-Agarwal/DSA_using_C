#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
struct node*front=NULL;
struct node* rear= NULL;
int n;
void enqueue_front(int x)
{
	if(n!=0)
	{
		struct node*newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==0)
		printf("\nMemory not allocated\n");
		else
		{
		newnode->data=x;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(front==0 && rear==0)
		{
			front=rear=newnode;
		}
		else
		{
			front->prev=newnode;
			newnode->next=front;
			front=newnode;
		}
		n--;
	    }
	}
	else
	printf("\nYou have reached the maximum element insertion\n");
}
void enqueue_rear(int x)
{
	if(n!=0)
	{
		struct node*newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==0)
		printf("\nMemory not allocated");
		else
		{
		newnode->data=x;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(front==0 && rear==0)
		{
			front=rear=newnode;
		}
		else
		{
			rear->next=newnode;
			newnode->prev=rear;
			rear=newnode;
		}
		n--;
		}
	}
	else
	printf("\nYou have reached the maximum element insertion\n");
}
void dequeue_front()
{
	struct node*temp;
	if(front==0 && rear==0)
	printf("\nQueue is empty\n");
	else if(front==rear)
	{
		temp=front;
		front=rear=NULL;
		n++;
		printf("\nDeleted element=%d\n",temp->data);
	}
	else
	{
		temp=front;
		front->prev=0;
		front=front->next;
		n++;
		printf("\nDeleted element=%d\n",temp->data);
	}
	free(temp);
}
void dequeue_rear()
{
	struct node*temp;
	if(front==0 && rear==0)
	printf("\nQueue is empty\n");
	else if(front==rear)
	{
		temp=front;
		front=rear=NULL;
		n++;
		printf("\nDeleted element=%d\n",temp->data);
	}
	else
	{
		temp=rear;
		rear=rear->prev;
		rear->next=0; 
		n++;
		printf("\nDeleted element=%d\n",temp->data);
	}
	free(temp);
}
void getfront()
{
	if(front==0 && rear==0)
	printf("\nQueue is empty\n");
	else
	printf("\nThe data at front is %d\n",front->data);
}
void getrear()
{
	if(front==0 && rear==0)
	printf("\nQueue is empty\n");
	else
	printf("\nThe data at rear is %d\n",rear->data);
}
void isfull(int n1)
{
	int N=length();
	if(n1==N)
	printf("\nQueue is full\n");
	else
	printf("\nQueue is not full\n");
}
void isempty()
{
	if(front==0 && rear==0)
	printf("\nQueue is empty\n");
	else
	printf("\nQueue is not empty\n");
}
int length()
{
	int count=0;
	if(front==NULL)
	{
		printf("\n underflow\n");
	}
	else
	{
		struct node*temp;
		temp=front;
		while(temp!=NULL){
			temp=temp->next;
			count++;}
	}
		return count;
}
void display()
{
	struct node*temp;
	temp=front;
	if(front==NULL && rear==NULL)
	printf("Queue is empty");
	else
	{
		printf("\n\tPrinting values\t\n");
		while(temp!=NULL)
		{
		printf("\n%d",temp->data);
		temp=temp->next;	
		}
	}
	free(temp);
}
int main()  
{
    printf("\nEnter number of nodes you want to insert:\n");
    scanf("%d",&n);
    int n1=n;
    int choice,x;
    do
    {
    	printf("\nEnter 0 to exit \nEnter 1 to enqueue at front \nEnter 2 to enqueue at rear\nEnter 3 to dequeue at front\nEnter 4 to dequeue at rear\nEnter 5 to get front element\nEnter 6 to get rear element\nEnter 7 to check if the deque is full\nEnter 8 to check if the deque is empty\nEnter 9 to display: ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 0:
    			printf("\nProgram Terminated\n");
    			exit(0);
    			break;
    		case 1:
				printf("\nEnter the data: ");
				scanf("%d",&x);
				enqueue_front(x);
			    break;
			case 2:
				printf("\nEnter the data: ");
				scanf("%d",&x);
				enqueue_rear(x);
				break;
			case 3:
				dequeue_front();
				break;
			case 4:
				dequeue_rear();
				break;
			case 5:
				getfront();
				break;
			case 6:
				getrear();
				break;
		    case 7:
		    	isfull(n1);
		    	break;
		    case 8:
		    	isempty();
		    	break;
		    case 9:
		    	display();
		    	break;
			default:
			printf("\nEnter Valid choice!!!!");
			break;	
		}
	}while(choice!=0);
     return 0;  
}  

