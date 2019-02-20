#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   struct node *next;
   struct node *prev;
};

//this link always point to first Link
struct node *head = NULL;

//this link always point to last Link 
struct node *last = NULL;

struct node *current = NULL;

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

//display the list in from first to last
void displayForward() {

   //start from the beginning
   struct node *ptr = head;
	
   //navigate till the end of the list
   printf("\n[ ");
	
   while(ptr != NULL) {        
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//display the list from last to first
void displayBackward() {

   //start from the last
   struct node *ptr = last;
	
   //navigate till the start of the list
   printf("\n[ ");
	
   while(ptr != NULL) {    
	
      //print data
      printf("(%d) ",ptr->data);
		
      //move to next item
      ptr = ptr ->prev;
      
   }
	
}

//insert link at the first location
void insertFirst( int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //update first prev link
      head->prev = link;
   }

   //point it to old first link
   link->next = head;
	
   //point first to new first link
   head = link;
}

//insert link at the last location
void insertLast(int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //make link a new last link
      last->next = link;     
      
      //mark old last node as prev of new link
      link->prev = last;
   }

   //point last to new last node
   last = link;
}

//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
   //if only one link
   if(head->next == NULL){
      last = NULL;
   } else {
      head->next->prev = NULL;
   }
	
   head = head->next;
   //return the deleted link
   return tempLink;
}

//delete link at the last location

struct node* deleteLast() {
   //save reference to last link
   struct node *tempLink = last;
	
   //if only one link
   if(head->next == NULL) {
      head = NULL;
   } else {
      last->prev->next = NULL;
   }
	
   last = last->prev;
	
   //return the deleted link
   return tempLink;
}

void getFront(){
  if(head!=NULL)
    printf("Element at front is: %d\n", head->data);
  else 
    printf("Deque is empty\n");
}

void getBack(){
  if(head!=NULL)
    printf("Element at back: %d\n", last->data);
  else 
    printf("Deque is empty\n");
}

int main() {
   insertFirst(10);
   insertFirst(20);
   insertFirst(30);
   insertFirst(1);
   insertFirst(40);
   insertFirst(56); 

   printf("\nList (First to Last): ");  
   displayForward();
	
   printf("\n");
   printf("\nList (Last to first): "); 
   displayBackward();

   printf("\nList , after deleting first record: ");
   deleteFirst();        
   displayForward();

   printf("\nList , after deleting last record: ");  
   deleteLast();
   displayForward();

   printf("\n\nisEmpty() Output: %d\n",isEmpty());

   printf("\ngetFront() Output:\n");  
   getFront();
   
   printf("\ngetBack() Output:\n");  
   getBack();

   return 0;
}
