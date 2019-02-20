// To find the middle element of given linked list


#include<stdio.h> 
#include<stdlib.h> 
  
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next;   //pointer to the next node in the linked list
}; 
  
/* Function to get the middle of the linked list*/
struct Node * deleteMiddle(struct Node *head) 
{
    // Base cases 
    if (head == NULL) 
        return NULL; 
    if (head->next == NULL) 
    { 
        delete head; 
        return NULL; 
    } 

 
    /*Traverse linked list using two pointers. Move one pointer by one step and other pointer by two steps. 
     When the fast pointer reaches end slow pointer will reach middle of the linked list.*/

    struct Node *slow_ptr = head; 
    struct Node *fast_ptr = head; 
  
    struct Node *prev; // To store previous of slow_ptr 

    while (fast_ptr != NULL && fast_ptr->next != NULL) 
    { 
        fast_ptr = fast_ptr->next->next; 
        prev = slow_ptr; 
        slow_ptr = slow_ptr->next; 
    } 

    printf("The middle element is : %d \n",slow_ptr->data);

    //Delete the middle node 
    prev->next = slow_ptr->next; 
    delete slow_ptr; 
  
    return head; 
  
} 
  
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
// A utility function to print a given linked list 
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
    
    //calling function to delete middle element
    head = deleteMiddle(head);
    
    printf("The linked list after deletion of middle element is: \n");
    printList(head);
  
    return 0; 
} 