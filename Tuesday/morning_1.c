
//					IMPLEMENTING TWO STACKS USING SINGLE ARRAY


#include<stdio.h>
#include<malloc.h>

int push(int *arr,int* head,int stack,int value)					//function for pushing a value in stack
{
    if(stack==1)									//for stack 1 starting from 0
    {
        if(head[0] + 1 < head[1])							//overflow condition if the new element is to be inserted 		{										//in stack one
            head[0] = head[0]+1;							//incrementing head
            arr[head[0]] = value;							//assigning the value
        }
        else
        {
            printf("Overflow\n");
            return 0;
        }
    }
    else if(stack==2)									//for stack 2 starting from n (ending of array)		
    {
        if(head[1] - 1  > head[0])							//overflow condition if the new element is to be inserted
        {										//in second stack
            head[1] = head[1]-1;							
            arr[head[1]] = value;
        }
        else
        {
            printf("Overflow\n");
            return 0;
        }
    }
    else										
    {
        printf("Wrong Stack Selected\n");
        return 0;
    }
    return 1;
}

int pop(int *arr,int* head,int stack,int n)						//function to pop a value from stack
{
    if(stack==1)									//for stack 1 starting from 0
    {
        if(head[0]>=0)									//underflow condition if the element is to be deleted
        {										//from stack one
            head[0] = head[0]-1;							
            return arr[head[0]+1];							//no need to remove the value stored.
        }				
        else
        {
            printf("Underflow\n");
            return 0;
        }
    }
    else if(stack==2)									//for stack 2 starting from n (ending of array)
    {
        if(head[1]<n)									//underflow condition if the element is to be deleted
        {										//from second stack
            head[1] = head[1]+1;									
            return arr[head[1]-1];							//no need to remove the value stored.
        }
        else
        {
            printf("Underflow\n");
            return 0;
        }
    }
    else
    {
        printf("Wrong Stack Selected\n");
        return 0;
    }
    return 0;
}

int top(int *arr,int* head,int stack,int n)						//function to return the top element of stack
{
    if(stack==1)									//for stack 1 starting from zero
    {
        if(head[0]>=0)									//if stack is empty head is less than zero or NULL
        {
            return arr[head[0]];
        }
        else
        {
            printf("Stack Empty\n");
            return 0;
        }
    }
    else if(stack==2)									//for stack 2 starting from n (ending of array)
    {
        if(head[1]<n)
        {
            return arr[head[1]];
        }
        else
        {
            printf("Stack Empty\n");
            return 0;
        }
    }
    else
    {
        printf("Wrong Stack Selected\n");
        return 0;
    }
    return 0;
}

int main()
{
    int n,choice,val,head[2],stk;							
	printf("Enter The Average Size Of Stack:\n");
	scanf("%d",&n);
	int* arr = (int*)calloc(2*n,sizeof(int));					//calloc is used to initialise the 2*n number of blocks 
    head[0] = -1;								 	//head of first stack
    head[1] = n;									//head of second stack
    int ret;
	do										//do-while loop for menu
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Top\n");
		printf("4. Exit\n");
		scanf("%d",&choice);
		
		if(choice != 3)
		{
		    printf("Choose The Stack You Want to perform Action On (1/2) : ");	 
		    scanf("%d",&stk);
		}

		switch(choice)
		{
			case 1:	   printf("Enter The Value : ");			
		                   scanf("%d",&val);					//scaning the value to be inserted
		                   ret = push(arr,head,stk,val);
				   break;
			case 2:	   ret = pop(arr,head,stk,n);
				   printf("The Data Popped Is : %d\n",ret);
				   break;
			case 3:    ret = top(arr,head,stk,n);
                   		   printf("The Data On Top Is : %d\n",ret);
				   break;
		}
	}
	while(choice!=4);								
    return 0;
}
