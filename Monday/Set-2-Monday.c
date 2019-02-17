/*Program to print binary repesentaion of 1 to n using
 Queue(implemented using Linked List)
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/* defining structure of linked list node and
 queue's structure with a front and rear node pointers*/

struct node
{
	char data[1000];
	struct node *next;
};

typedef struct
{
	struct node *front, *rear;
}queue;

// function prototype declarations
void printBin(int n);
void enQueue(queue* q, char* a);
char* deQueue(queue* q);

//declaration of global variable used in deQueue function to return string
char a[1000];

// main function
int main()
{
	int n;
	printf("Enter Value of n: ");
	scanf("%d",&n);
	while(getchar() != '\n'); // flushing the input buffer is a good practice
	
	printBin( n ); // calling the printBin() function
	
	return 0;
}

/* Function to print binary representation of 1 to n*/
void printBin(int n)
{
	if(n < 1)
		return;
		
	queue* q = (queue*)malloc(sizeof(queue));
	
	int max_len = (int)floor(log(n)) + 2; // (length of binary representation of n) + 1
	char str1[max_len], str2[max_len];
	str1[0] = str2[0] = '\0';
	
	enQueue(q, "1");
	
	while(n--)
	{
		char *bin = deQueue(q);
		if(bin == NULL)
			break;
		strcpy(str1, bin);
		printf("%s\n",str1);
		strcpy(str2, str1);
		
		strcat(str1, "0");
		enQueue(q, str1);
		
		strcat(str2, "1"); // note that str2 contain value of str1 before appending 0 
		enQueue(q, str2);
	}
}
	
		

// functions of queue data structure
void enQueue(queue* q, char* a)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data[0] = '\0';
	strcpy(temp->data, a);
	temp->next = NULL;
	
	if(q->rear == NULL)
	{
		q->rear = q->front = temp;
		return;
	}
	
	q->rear->next = temp;
	q->rear = temp;
}

char* deQueue(queue* q)
{
	if(q->front == NULL)
		return NULL;
		
	a[0] = '\0';
	strcpy(a, q->front->data);
		
	if(q->front == q->rear)
	{
		free(q->front);
		q->rear = q->front = NULL;
		return a;
	}
	
	struct node* temp;
	temp = q->front;
	q->front = q->front->next;
	free(temp);
	temp = NULL;
	return a;
}
