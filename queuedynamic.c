#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};

struct node*front=NULL;
struct node*rear=NULL;
int n,n1; 
void enqueue();
void dequeue();
void display();
void peek();
void isempty();
void isfull();
int length();
void main()
{
   int choice;
   printf("Enter the number of elements in queue:\n");
   scanf("%d",&n);
   n1=n;
   do
   {
   	printf("\n\nEnter 0 to exit\n1 to Enqueue\n2 to Dequeue\n3 to Display\n4 to Peek\n5 to check if it is empty\n6 to check if it is full\n");
   	scanf("%d",&choice);
   	switch(choice)
   	{
   	    case 0:
   	    	{
		  printf("Program terminated");
		  exit(0);
		  break;}
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
			isempty();
			break;
			case 6:
			isfull();
			break; 
            default:   
            printf("\nEnter valid choice!!\n");  
    }  
 }while(choice!=0);  	
}
void enqueue()
{
	if(n1!=0){
	int item;  
    printf("\nEnter the element\n");  
    scanf("%d",&item);
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	printf("\nOverflow\n");
	newnode->data=item;
	if(front==0 && rear==0)
	{
	   	front=newnode;
	   	rear=newnode;
	   	front->next=NULL;
	   	rear->next=NULL;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		newnode->next=NULL;
	} 
	printf("\nValue inserted\n");
		n1--; 
	}
	else{
		printf("NO VALUE CAN BE INSERTED\n");
		return;
	}
}
void dequeue()
{
	struct node*temp;
	if(front==NULL && rear==NULL)
	printf("Queue is empty");
	else if(front==rear)
	{
		temp=front;
		front=NULL;
		rear=NULL;
		n1++;
	}
	else
	{
		temp=front;
		front=front->next;
		free(temp);
		n1++;
	}
	printf("Value Deleted");
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
}
void peek()
{
	if(front==NULL)
	printf("\nEmpty queue\n");
	else
	printf("\n%d\n",front->data);
}
void isempty()
{
	int N=length();
	if(n==N)
	printf("\nQueue is not empty\n");
	else
	printf("\nQueue is empty\n");
}
void isfull()
{
	int N=length();
	if(n==N)
	printf("Queue is full\n");
	else
	printf("Queue is not full\n");
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
