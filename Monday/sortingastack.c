#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;
};
void display(struct node *h);
struct node* createnode(int  val);
void insertnodeatlast(struct node *h, int val);
void push(struct node **h,int val);
struct node* pop(struct node **h);
void top(struct node *h);
void isempty(struct node *h);

void findmax(struct node **head);


void main()
{
int data,num,n,t=0,k,ans,max;
char str[5];
 struct node *head=NULL,*head1=NULL;
 struct node *temp, *temp1;

//Creating The Stack Of N size
printf("Enter The Size of The Stack: ");
scanf("%d",&n);
   while(t!=n)
 {
   printf("Enter the value to be pushed:");
   scanf("%d",&num);
   if(num<0)
	break;
   push(&head,num);
   t++;
 }      

//Displaying Stack
printf("The Stack is : ");
display(head);

//Asking For Number of operations
printf("\n\n Enter The Number of Opertions :");
scanf("%d",&k);
 
//Performing K operations
printf("\n\nWould you Like To:\n 1.Pop an element \n 2.Push the Popped \n");
while(k!=0)
{ 
  scanf("%d",&ans);
  	switch(ans)
       {      
	case 1:temp=pop(&head);
		 break;
	case 2:temp1=pop(&head);
		 push(&head,temp1->data);
		 break;
	default: printf("Wrong choice ! ");
		 break;
        }
 if(k!=1)
 printf("Enter your choice again..");
k--;
}
display(head);	 
findmax(&head);

}
struct node* createnode(int val)
{      struct node *temp;
	  temp = (struct node*)malloc(sizeof(struct node));
      temp->data = val;
      temp->next = NULL;
      return temp;
}
void insertnodeatlast(struct node *h,int val)
{
	struct node *temp;
	temp = createnode(val);
	while(h->next != NULL)
	   h= h->next;
	h->next = temp;
}
void display(struct node *head)
{
	printf("Head->");
	 while(head!=NULL)
	 {
	 	 printf("%d->", head->data);
	 	 head = head->next;
	 }
	 printf("NULL)");
}

void push(struct node **head,int val)		//Push in Stack
{
	struct node *temp;
	temp=createnode(val);
	
	temp->next=*head;
	*head=temp;
}	
struct node* pop(struct node **head)	       //Pop in Stack
{
  struct node *temp=*head; 

  if(*head==NULL) 
      printf("The stack is empty..");	    
  
  *head=(*head)->next;   
 

return temp;
}

void findmax(struct node **head)              //Find Max Of Stack
{ struct node *temp=*head;
int max;
max=temp->data;

while((*head)->next!=NULL)
{ 
	temp=*head;
	*head=(*head)->next;

	if(((*head)->data)>max)
	max=(*head)->data;
	
}

printf("\n\n Maximum is %d",max);
}
