// Program to find n'th node from end 

#include<stdio.h> 
#include<stdlib.h> 
  
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
/* Function to get the nth node from the last of a linked list*/
void findnodeN(struct Node* head, int n) 
{ 
    int len = 0, i; 
    struct Node *temp = head; 
  
    // count the number of nodes in Linked List 
    while (temp != NULL) 
    { 
        temp = temp->next; 
        len++; 
    } 
  
    // check if value of n is not more than length of the linked list 
    if (len < n) 
    return; 
  
    temp = head; 
  
    // to get the (len-n+1)th node from the beginning i.e. equivalent to nth node from head of linked list
    
    for (i = 1; i < len-n+1; i++) 
    temp = temp->next; 
  
    printf ("The node %d from the end %d",n,temp->data); 
  
    return; 
} 

//inserting in beginning
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
            (struct Node*) malloc(sizeof(struct Node)); 
      
    /* put in the data */
    new_node->data = new_data; 
      
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
      
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 

//print linked list
void printList(struct Node *ptr) 
{ 
    while (ptr != NULL) 
    { 
        printf("%d->", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); //note: NULL is not a part of the linked list
} 

/* Driver program to test above function*/
int main() 
{ 
 /* Start with the empty list */
    struct Node* head = NULL;

    int i,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
  
    printf("Enter the list: ");
    
    for (i=n; i>0; i--) 
    { 
        int ele;
        scanf("%d",&ele);
        push(&head, ele);
    } 
    
    printf("The list is : \n");
    printList(head);
    
    int x;
    printf("Enter the node number which you want to find (1 to n): ");
    scanf("%d",&x);
    
    findnodeN(head, x); 
    return 0;  
} 
