#include<stdio.h>
#include<stdlib.h>

int i = -1;				//to keep count of the index
int stack[10]; 			//assuming there are max of 10 elements that can entered in the stack

void push(int x){
	if(i>=10){
		printf("Stack full\n");
	}
	else if(i<10){
		int x;
		printf("Enter the integer you want to push: ");
		scanf(" %d", &x);
		i++;
		stack[i] = x;
	}
}

int isEmpty(){
	if(i<0)
		return 1;
	else 
		return 0;
}

void peek(){
	if(!isEmpty())
		printf("The topmost element is: %d\n",stack[i]);
	else{
		printf("Stack is empty\n");
	}	
}

void pop(){
	if(!isEmpty())
		printf("The popped element is: %d\n",stack[i--]);
	else{
		printf("Stack is empty\n");
	}
}


void printStack(){
	if(!isEmpty()){
		printf("Stack:\n");
		for(int j = i ; j >= 0 ; j--){
			printf(" %d\n", stack[j]);
		}
	}
	else{
		printf("Stack is Empty\n");
	}
}

int main(){
	while(1){
		int d,x;
		printf("\n{1.Push 2.Peek 3.Pop 4.Print_Stack 5.To exit}\n\nEnter the function you want to perform: ");
		scanf(" %d", &d);
		switch(d){
			case 1:{
				push(x);
				break;
			}
			case 2:{
				peek();
				break;
			}
			case 3:{
				pop();
				break;
			}
			case 4:{
				printStack();
				break;
			}
			case 5:
				exit(0);
			default:{
				printf("Invalid selection\n");
			}
		}
	}
	return 0;
}

