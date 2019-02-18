//C program to implement queue using array


#include<stdio.h>
#include<stdlib.h>
#define size 50
int queue[size];  //declaring array of size 50
int front=-1,rear=-1;  //these variable will point to the start and the end of the array
void insert(void){
	if(rear==size-1)    //it will check if array is already full or not
		printf("\noverflow");
	else{
		if(front==-1)         //entering data for the first time then we have to increase front by 1
			front=0;
		printf("\nEnter data");
		rear++;
		scanf("%d",&queue[rear]);
	}
}
void delete(void){
	 if (front==-1 || front>rear)  //checking if queue is empty or not
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("deleted element is : %d\n", queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if (front==-1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main(){
	int choice;
	while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        	case 1:
        			insert();
        			break;
            case 2:
            		delete();      
            		break;
            case 3:
            		display();
            		break;
            case 4:
            		exit(1);
            default:
           			printf("Wrong choice \n");
        }
    }
    return 0;
}

