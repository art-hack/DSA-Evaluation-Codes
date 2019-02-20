# include <stdio.h>
# include <stdlib.h>

struct node  //defining a node structure
{
    int data;
    struct node* next;
};


//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------



void sortedAdd(struct node* ll,int x) //function to add elements to list in sorted order. Complexity O(n)
{
   
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    /*
        Create a new node using malloc. 
        Creating a node using a local variable will cause a segmentation fault since it will be destroyed after function ends.
    */
    newNode->data=x; //setting data of node
    
    

    if(ll->next==NULL) //if list is empty
    {
        ll->next=newNode; //append node to empty list
        newNode->next=NULL; //set pointer of node to null
    }
    
    
    else
    {
        
        struct node* temp= ll;
        struct node* temp2 =temp->next; 
        /*
            2 variables for traversing list.
            temp2 traverses list and temp points to previous node
        */        
        
        while(temp2!=NULL && temp2->data<x)
        {
            temp=temp->next;
            temp2=temp2->next;
        }
        /*
            After traversal, we should add node before temp2.
            If temp2 is null, code will still work as node will append at end.
            
            Since temp points to previous node,  we must insert node b/w temp and temp2
        */
        
        
        
        temp->next=newNode;
        newNode->next=temp2;
    
        
    }
    
    (ll->data)++; //increase number of elements in list by one
    printf("Added %d succesfully\n",x);
}




void printList(struct node* ll)//prints all elements by traversing. Complexity O(n)
{
    struct node* temp=ll->next;
    if(temp==NULL) {printf("List is empty");} //another way was checking if (ll->data==0)
    else 
    {
        for(int i=1;i<=ll->data;i++)        
        {
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}


void removeDuplicates(struct node* ll)//Remove duplicate elements of link list. Complexity O(n)
{
    if(ll->data==0) return; //if list is empty, return
    
    struct node* temp=ll->next; //temp pointer points to first node
    
    
    struct node* temp2= temp->next; //temp2 points to next node of temp
    
    while(temp2!=NULL) //traverse with temp2
    {
        if(temp2->data==temp->data) //if match found, delete
        {
            temp->next=temp2->next;
            free(temp2);
            /*
                Free memory after deleting a node. 
                Dynamically created memory is assigned from program heap.
                Unlike variables, they are not destroyed till program ends and will eat up space
            */
            temp2=temp->next;
            (ll->data)--; //reduce number of elementss in list by 1
        }
        
        else //if match not found, traverse
        {
            temp=temp2;
            temp2=temp->next;
        }
    }
    
        
    
}



int main()
{
    struct node linkList;
    linkList.next=NULL;
    linkList.data=0;
    
    /*
        First node is start node. Its pointer points to link list and data gives number of elements in link list.
        It has advantage of giving count  of elements in O(1) and also avoids using double pointers
    */
    
    
    //Testing adding elements
    int temp,n;
    printf("Enter number of elements to add: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        sortedAdd(&linkList,temp);
    }
    
    printf("Elements in link list are: ");
    printList(&linkList);
    
    removeDuplicates(&linkList);
    
    printf("Elements in link list after removing duplicate elements: ");
    printList(&linkList);
    return 0;
}



//Optional function to remove elements from link list. 



/*
void deleteFromList(struct node* ll, int x)
{
    if(ll->data==0) {printf("List is empty\n"); return;}
    struct node* temp=ll;
    struct node*temp2=temp->next;
    while(temp2!=NULL)
    {
        
        if(temp2->data==x)
        {
            temp->next=temp2->next;
            free(temp2);
            (ll->data)--;
            printf("Successfully deleted %d\n",x);
            return;
        }
        
        
        temp2=temp2->next;
        temp=temp->next;
    }
    
    printf("Element was not present in list\n");
    
}
*/
