#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
   
//Represent a node of binary tree  
struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
};  
   
//Represent the root of binary tree  
struct node *root= NULL;  
   
//createNode() will create a new node  
struct node* create(int data){  
    //Create a new node  
    struct node *newNode; 
	newNode= (struct node*)malloc(sizeof(struct node));  
    //Assign data to newNode, set left and right children to NULL  
    newNode->data= data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
    return newNode;  
}  
   
//insert() will add new node to the binary search tree  
void insert()
{
      int info; 
	  printf("\nEnter data: ");
	  scanf("%d",&info);   
    //Create a new node  
    struct node *newNode = create(info);  
      
    //Check whether tree is empty  
    if(root == NULL)
	{  
        root = newNode;  
        return ;  
    }  
    else
	{  
        //current node point to root of the tree  
        struct node *current = root, *parent = NULL;  
          
        while(true) {  
            //parent keep track of the parent node of current node.  
            parent = current;  
   
            //If data is less than current's data, node will be inserted to the left of tree  
            if(info < current->data) {  
                current = current->left;  
                if(current == NULL) {  
                    parent->left = newNode;  
                    return;  
                }  
            }  
            //If data is greater than current's data, node will be inserted to the right of tree  
            else if(info > current->data) {  
                current = current->right;  
                if(current == NULL) {  
                    parent->right = newNode;  
                    return;  
                }  
            }
			else if(info==current->data)
			{
				printf("Duplicate!!"); 
				return;
			}
			 
        }  
}  

}
  
//minNode() will find out the minimum node  
struct node* minNode(struct node *root) {  
    if (root==0 && root->left != NULL)  
        return minNode(root->left);  
    else   
        return root;  
}   
   
//deleteNode() will delete the given node from the binary search tree  
struct node* deleteNode(struct node *node, int value) {  
    if(node == NULL){  
          printf("\nELEMENT NOT FOUND\n");
		  return 0;  
     }  
    else {  
        //value is less than node's data then, search the value in left subtree  
        if(value < node->data)  
            node->left=deleteNode(node->left, value);  
          
        //value is greater than node's data then, search the value in right subtree  
        else if(value > node->data)  
            node->right=deleteNode(node->right, value);  
          
        //If value is equal to node's data that is, we have found the node to be deleted  
        else {
		  
            //If node to be deleted has no child then, set the node to NULL  
            if(node->left == NULL && node->right == NULL)
			{
				struct node *temp=0;
				free(node);
				puts("Value Deleted");
				return temp;
            }   
              
            //If node to be deleted has only one right child  
            else if(node->left == NULL)
			{
				puts("Value Deleted");
				struct node *temp= node->right; 
				free(node);
				return temp; 
            }  
              
            //If node to be deleted has only one left child  
            else if(node->right == NULL)
			{
				puts("Value Deleted");
				struct node *temp= node->left;
			    free(node); 
			    return temp;
            }  
              
            //If node to be deleted has two children node  
            else
			{ 
			    struct node *temp; 
                //then find the minimum node from right subtree  
                temp = minNode(node->right);  
                //Exchange the data between node and temp  
                node->data = temp->data;  
                //Delete the node duplicate node from right subtree  
                node->right=deleteNode(node->right, temp->data);
                puts("Value Deleted");
            }
            }
        }
		    
}

void search(struct node*node,int value)
{
   if(node==NULL)
   {
   	printf("\nValue does not exist\n");
   	return;
   }
   else
   {
	   	if(value<node->data)
	   	search(node->left,value);
	   	else if(value>node->data)
	   	search(node->right,value);
	   	else
	   	printf("Value found %d",node->data);
   }	
}  
   
//inorder() will perform inorder traversal on binary search tree 
 
void inorderTraversal(struct node *node) {  
        
    //Check whether tree is empty  
    if(root == NULL){  
        printf("Tree is empty\n");  
          return;  
     }  
    else {  
            
        if(node->left!= NULL)  
            inorderTraversal(node->left);  
        printf("%d ", node->data);  
        if(node->right!= NULL)  
          inorderTraversal(node->right);        
} 
}
void main()  
{  
    //Add nodes to the binary tree  
    insert();
    int choice;
	do
	{
	   printf("\nIf you want to insert more press 1,press 2 to delete,press 3 to print,press 4 to search,else press 0: ");
	   scanf("%d",&choice);
	   if(choice==0)
	   {
	   	printf("\nProgram Terminated");
	   	exit(0);
	   }
	   else if(choice==1)
		{
			insert();
		}
		else if(choice==2)
		{
			if(root==0)
			printf("\nTree is empty\n");
			else
			{
			int value;
			printf("\nEnter the value you want to delete: ");
			scanf("%d",&value);
			deleteNode(root,value);
		    }
		}
		else if(choice==3)
		{
			puts("Binary search tree: \n");
			inorderTraversal(root);
		}
		else if(choice==4)
		{
			if(root==0)
			printf("\nTree is empty\n");
			else
			{
			int value;
			printf("\nEnter the value to search: ");
			scanf("%d",&value);
			search(root,value);
		    }
		}
		else
		{
			printf("\nEnter valid choice!");
			}	
	}while(choice!=0); 
}
