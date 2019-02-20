#include<stdio.h>
#include<stdlib.h>

void push(int *arr, int *ind, int data){
    if(*ind >= 9){
        printf("Stack_full\n");
    }
    else{
        *ind = *ind + 1;
        arr[*ind] = data;
    }
}

int isEmpty(int ind){
	if(ind<0)
		return 1;
	else
		return 0;
}

int pop(int *arr, int *d){
	if(!isEmpty(*d)){
	    int c = *d;
		*d=*d-1;
		return arr[c];
	}
	else{
		printf("Stack is empty\n");
	}
}

int peek(int *arr, int d){
    if(!isEmpty(d)){
		return arr[d];
	}
	else{
		printf("Stack is empty\n");
	}
}

void printStack(int *arr, int ind){
    for(int i = ind ; i>=0; i--){
        printf("%d\n",arr[i]);
    }
}

void sort(int *o_arr, int *h_arr, int *o_ind, int *h_ind){
    int popped;
    while (!isEmpty(*o_ind)){
        popped = pop(o_arr, o_ind);
        while(!isEmpty(*h_ind) && peek(h_arr,*h_ind) < popped){
            push(o_arr,o_ind,pop(h_arr,h_ind));
        }
        push(h_arr,h_ind,popped);
    }
    printf("\nThe sorted stack is:\n");
    printStack(h_arr,*h_ind);
}

void main(){
    int orig_stack[10];
    int helper_stack[10];
    int o_ind = -1;
    int h_ind = -1;
    push(orig_stack,&o_ind,56);
    push(orig_stack,&o_ind,2);
    push(orig_stack,&o_ind,44);
    push(orig_stack,&o_ind,32);
    push(orig_stack,&o_ind,78);
    push(orig_stack,&o_ind,10);
    push(orig_stack,&o_ind,98);
    push(orig_stack,&o_ind,52);
    push(orig_stack,&o_ind,14);
    push(orig_stack,&o_ind,23);
    printf("Original Stack:\n");
    printStack(orig_stack, o_ind);
    sort(orig_stack, helper_stack, &o_ind, &h_ind);
}

