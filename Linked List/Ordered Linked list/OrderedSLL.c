
#include <stdio.h>
#include<stdlib.h> //for malloc


typedef struct OrderedSLL
{
    int data;
    struct OrderedSLL *next;
}OrderedSLL;

OrderedSLL *head;

//Creating the Ordered SLL - Descending Order
void createOrderedSLL()
{
    OrderedSLL *ptr, *newnode, *prev;
    ptr = newnode = prev = NULL;
    int datavalue;
    
    
    printf("Enter Data for Ordered Single Linked List\n");
    scanf("%d", &datavalue);
    
    
    newnode = (OrderedSLL *)malloc(sizeof(OrderedSLL));
    
    newnode->data = datavalue;
    
    newnode->next = NULL; 
    if(head == NULL) //'head' == NULL initially
        head = newnode ; 
    else
    {
        
        if(newnode->data > head->data)
        {
            newnode->next = head;
            head = newnode; //Newnode becomes head
        }
        else
        {
            ptr = head;
            
            while( (ptr!= NULL) && (newnode->data  < ptr->data) )
            {
                prev = ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL)    
            {
                prev->next = newnode;
                newnode->next = ptr; 
            }
            else 
            {
                prev->next = newnode;
                newnode->next = ptr;
            }
        }
    }
    
}


void displayOrderedSLL()
{
    OrderedSLL *ptr;
    if(head == NULL)
    {
        printf("\nEmpty Bakery \n");
        return;
    }
    ptr = head; int count = 0;
    while(ptr!= NULL) 
    {
        printf("\nNode#%d. Data is: %d-->", ++count,ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    int choice;
    for(;;)
    {
        printf("\n\n***MENU OPTIONS***\n1.Create Ordered SLL\n2.Display In descending order\n3.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                createOrderedSLL();
                printf("\nUse Option 3 to display the Ordered SLL After Creation");
                break;
            case 2:
                printf("\n Ordered SLL Items in descending order of price are ");
                displayOrderedSLL();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid option\n\n");
                break;
        }
    }
}



