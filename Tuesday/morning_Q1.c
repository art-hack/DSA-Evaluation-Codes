#include<stdio.h>
#define MAX 100
struct stack
{
	int top; 
	int bottom;
	int arr[MAX];
};

void push1(struct stack *a,int d)//push in 1st stack
{ 		if(a->top+1==a->bottom||a->top==MAX-1)
		printf("stack overflow\n");
		else
		{a->top=a->top+1;
	 	a->arr[a->top]=d;}
	
	 
}
void push2(struct stack *a,int d)//push in 2nd stack
{		if(a->bottom-1==a->top||a->bottom==0)
		printf("stack overflow\n");
		else
		{a->bottom=a->bottom-1;
		a->arr[a->bottom]=d;}
	
}

int pop1(struct stack *a)//pop from 1st stack
{
	int temp;
	if(a->top==-1)
		return -999;//assuming it is not a part of the stack
	temp=a->arr[a->top];
		a->top=a->top-1;
		return temp;
}
int pop2(struct stack *a)//pop from 2nd stack
{
	int temp;
	if(a->bottom==MAX)
		return -999;//assuming it is not part of stack
	temp=a->arr[a->bottom];
	a->bottom=a->bottom+1;
	return temp;
}
int isEmpty1(struct stack *a)//check if 1st stack is empty or not
{
	if(a->top==-1)
	return 1;
	else
	return 0;
}
int isEmpty2(struct stack *a)//check if stack 2 is empty
{
	if(a->bottom==MAX)
	return 1;
	else
	return 0;
}
void display1(struct stack a)//display elements of stack 1
{ printf("\nelements of stack 1 are ");
	while(a.top!=-1)
	{	 printf("%d ",a.arr[a.top]);
		 a.top=a.top-1;
	}
}

void display2(struct stack a)//display elements of stack 2
{ printf("\nelements of stack 2 are ");
	while(a.bottom!=MAX)
	{	 printf("%d ",a.arr[a.bottom]);
		 a.bottom=a.bottom+1;
	}
}
int top1(struct stack a)//to display top element of stack 1
{
	if(a.top!=-1)
	return a.arr[a.top];
	else
	return -999;//assumming it doesn't exist in stack
}
int top2(struct stack a)//to display the top element of stack 2
{
	if(a.bottom!=MAX)
	return a.arr[a.bottom];
	else
	return -999;//assumming it doesn't exist in stack
}

	
	
void main()
{
	struct stack a;
	a.top=-1;
	a.bottom=MAX;
	push1(&a,10);
	push1(&a,20);
	push1(&a,30);
	push1(&a,320);
	push2(&a,100);
	push2(&a,40);
	push2(&a,200);
	push2(&a,50);
	display1(a);
	display2(a);
	int b=pop1(&a);
	printf("\n%d",b);
	b=pop2(&a);
	printf("\n%d",b);
	display1(a);
	display2(a);
	b=top1(a);
	printf("\ntop elemet of stack 1 is %d \n",b);
	display1(a);
	
	}
