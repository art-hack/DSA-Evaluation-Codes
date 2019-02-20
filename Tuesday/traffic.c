#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node* next;
};

struct node* front = NULL;
struct node* back = NULL;

void enqueue(char x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node*));
	temp->data = x;
	temp->next = NULL;
	if(front == NULL && back == NULL)
	{
		front = back = temp;
	}
	else
	{
		back->next = temp;
		back = temp;
	}
}

void top()
{
	printf("The current signal is : %c",back->data);
}
void print()
{
	struct node* temp = front;
	{
		while(temp!= NULL)
		{
			printf("%c\n",temp->data);
			temp = temp->next;
		}
	}
}
int main()
{
	char r = 82;
	char g = 71;
	char y = 89;
	int e;
	int f;
	int x;
	int h;
	printf("Press 1 for Red, 2 for Green and 3 for yellow \n");
	scanf("%d",&e);
	
		if(e==1)
		{
			while(f!=0)
			{
				enqueue(r);
				top();
				printf("Press 0 to exit");
				scanf("%d",&f);
				if(f == 0)
				 break;
				enqueue(g);
				top();
				printf("Press 0 to exit");
				scanf("%d",&f);
				if(f == 0) 
					break;
				enqueue(y);
				top();
				printf("Press 0 to exit");
				scanf("%d",&f);
				if(f == 0) 
					break;
			}

		}
		if(e==2)
		{
			while(x!=0)
			{
				enqueue(g);
				top();
				printf("Press 0 to exit");
				scanf("%d",&x);
				if(x == 0) 
					break;
				enqueue(y);
				top();
				printf("Press 0 to exit");
				scanf("%d",&x);
				if(x == 0) 
					break;
				enqueue(r);
				top();
				printf("Press 0 to exit");
				scanf("%d",&x);
				if(x == 0)
				 break;
	}
}
if(e==3)
		{
			while(h!=0)
			{
				enqueue(y);
				top();
				printf("Press 0 to exit");
				scanf("%d",&h);
				if(h == 0)
				 break;
				enqueue(r);
				top();
				printf("Press 0 to exit");
				scanf("%d",&h);
				if(h == 0) 
					break;
				enqueue(g);
				top();
				printf("Press 0 to exit");
				scanf("%d",&h);
				if(h == 0) 
					break;
}
}
}
