#include <stdio.h>
#include <stdlib.h>
struct node
{
	char data;
	struct node *next;
};
void createnode(struct node **front,struct node **rear,char val);
void enqueue(struct node **rear, char val);
void dequeue(struct node **front);
void display(struct node *front,struct node *rear);
void circular(struct node **front,struct node **rear);
void check(struct node *bulb,struct node *front,struct node *rear,char val);
void main()
{
 int val;
 struct node *front1,*front2,*front3,*bulb;
 struct node *rear1,*rear2,*rear3;
char ch;
createnode(&front1,&rear1,'R');
enqueue(&rear1,'Y');
enqueue(&rear1,'G');
circular(&front1,&rear1);
printf("give color R,Y,G(case Sensitive capital only) ::");
scanf(" %c",&ch);
check(bulb,front1,rear1,ch);
//display(front1,rear1);
}
void createnode(struct node **front,struct node **rear,char val)
{
      struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
      temp->data = val;
      temp->next = NULL;
      *front=*rear=temp;
}
void enqueue(struct node **rear, char val)
{
	struct node *temp;
 temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
      temp->next = NULL;
	(*rear)->next=temp;
	*rear=temp;	      
	
}
void dequeue(struct node **front)
{
	struct node *temp;
	temp=*front;
	*front=(*front)->next;
	free(temp);
}
void display(struct node *front,struct node *rear)
{int count=0;	
	while (front!=NULL)
	{
		printf(" %c-->",front->data);
		front = front->next;	
	/*	count++;
	if (count==5)
break;*/
	}
}
void circular(struct node **front,struct node **rear)
{
	(*rear)->next=*front;

}	 
void check(struct node *bulb,struct node *front,struct node *rear,char val)
{
int count =0;
	while(front!=NULL)
	{
		if(front->data==val)
		{
			bulb = front;
			//bulb=bulb->next;
			break;
		}		
		front=front->next;
	}			
	while(bulb!=NULL)
	{
		printf(" %c-->",bulb->data);
		bulb=bulb->next;
		count++;
			if(count ==10)break;	
	}

}
