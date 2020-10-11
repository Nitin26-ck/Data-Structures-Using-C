
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ThreeB
{
    int rollno;
    char name[20];
    struct ThreeB *next;
    struct ThreeB *prev;
}ThreeB;
ThreeB *head, *tail;
ThreeB *searchptr;

int scount; //to count the number of student-nodes in the ThreeB list.
int srollno; //variable to enter the rollno to be assigned to the new student-node
char sname[20];//variable to enter the name to be assigned to the new student-node

void LLDemoOptions()
{
    printf("\n**** Singly Linked List Program. Having ONLY 'Insert' & 'Search' *** \n");
    printf("0.menu\n");
    printf("1.Search RollNo in Singly Linked List for ThreeB\n");
    printf("2.Insert At Any Position of Singly Linked List for ThreeB\n");
    printf("3.Display Students in Singly Linked List for ThreeB\n");
    printf("4.Delete any Student given the rollno\n");
    printf("-1.Quit Singly Linked List Program\n");
    
}//end LLDemoOptions

/*The  point to remember in the 'search' function is to return the pointer to the node which contains the 'rollno' searched. */
ThreeB * searchStudent(ThreeB * head, int srollno)
{
    ThreeB * pointer = head;
    if(head == NULL) {printf("\n Empty List"); return NULL;}
    else
    {
        while(pointer != NULL)
        {
            if(pointer->rollno == srollno)
                return pointer;
            
            else
                pointer = pointer->next;
        }
        return NULL;
    }
}//end of searchStudent

void printThreeBDetails(ThreeB * head)
{
    if(head == NULL)
    {
        printf("\nStudent Linked List is empty");
    }
    else
    {
        ThreeB * pointer = head;
        printf("\n Number of students in ThreeB is %d", scount);
        printf("\n ThreeB Student List head address %d ", head);
        while(pointer != NULL)
        {
            printf("\nRollNo: %d -> ",pointer->rollno);
            printf("  Name: %s-> ",pointer->name);
            pointer = pointer->next;//Helps Understand funda of current node
            printf("\nNext student node pointer address->%d ", pointer);/*Helps Understand funda of next node */
        }//end while
    }//end else
}//end printThreeBDetails


/*This is a generic function to create a new node. All five 'insert' conditions call this very same function. No code-change required to handle these five insert operations.  */
ThreeB * createNewStudent(ThreeB * next, ThreeB * prev)
{
    ThreeB * newStudent = (ThreeB *)malloc(sizeof(ThreeB));
    strcpy(newStudent->name,sname);
    newStudent->rollno = srollno;
    newStudent->next = next;
    newStudent->prev = prev;
    scount++;
    return newStudent;
}//end createNewStudent

ThreeB * insertAny(ThreeB * head)
{
    int position; // 0 means before 1 means after
    int rollposition;
    if(head == NULL)
    {
        printf("\n Congratulations - Very first student to enroll!");
        
        ThreeB * newStudent = createNewStudent(head,tail);
        head = newStudent; /*Very important. Dont forget this to do this!Otherwise you will never be able to print the new student node created.*/
        tail = head;
        return head;
    }//end of if list is empty
    
    else if(head != NULL)
    {
        ThreeB * posptr = NULL;
        
        printf("\nDo you want to insert after or before a roll number : Enter 0 for before, 1 for after? ");
        scanf("%d",&position);
        
        if(position == 0)
        {
            printf("\nEnter the Student RollNo you want to insert before ");
            scanf("%d",&rollposition);
        }
        else if(position == 1)
        {
            printf("\nEnter the Student RollNo you want to insert after ");
            scanf("%d",&rollposition);
        }
        else printf("\n Wrong value for position - enter 0 for before, 1 for after");
        
        posptr = searchStudent(head, rollposition);
        
        printf("\n posptr pointer address->%d and rollposition is %d", posptr, rollposition);
        if(posptr != NULL)
        {
            if (position == 1 && posptr->next ==NULL)
            {
                printf("\n In Insert Any : Insert After End Node ");
                ThreeB * newStudent = createNewStudent(NULL,posptr);
                posptr->next = newStudent;
            }
            else if(position == 1 && posptr->next !=NULL)
            {
                printf("\n In Insert Any : Insert After a middle Node ");
                ThreeB * newStudent = createNewStudent(posptr->next,posptr);
                newStudent->next->prev = newStudent;
                posptr->next = newStudent;
                
            }
            else if(position == 0 && posptr == head)
            {
                printf("\n In Insert Any : Insert Before Head Node ");
                ThreeB * newStudent = createNewStudent(head,NULL);
                head->prev = newStudent;
                head = newStudent;
            }
            else if(position == 0 && posptr != head)
            {
                printf("\n In Insert Any : Insert Before Middle Node ");
               
                    ThreeB * newStudent = createNewStudent(posptr, posptr->prev);
                    posptr->prev->next = newStudent;
                    posptr->prev = newStudent;
                    printf("\nposptr->prev->next address->%d and newStudent->%d", posptr->prev->next, posptr->prev);
                
            }//end of inner else for Insert Any : Insert Before Middle Node
            
        }//end of if node to be inserted before or after exists
        else
            if (position == 0)
                printf("\n Sorry! The roll# you want to insert before does not exist in the list");
            else
                printf("\n Sorry! The roll# you want to insert after does not exist in the list");
        
        
        return head;
    }// end of outermost else when list is not empty
}//end of insertAny

ThreeB * deleteAny(ThreeB * head, int srollno)
{
   
    ThreeB * delptr = searchStudent(head, srollno);
    
    printf("\n delptr address %d->", delptr);
    if(delptr == NULL)
    {
        printf("\n The roll number you want to delete does not exist in the list");
        return head;
    }
    else
    {
        if(delptr == head)
        {
            printf("\n You are deleting the head node");
            head = delptr->next;
            //head->prev = NULL; /* Giving segmentation fault when this line is executed. Not needed */
            free(delptr); scount--;
        }
        else if(delptr->next == NULL)
        {
            printf("\n You are deleting the last node");
            delptr->prev->next = NULL;
            free(delptr); scount--;
        }
        else
        {
            printf("\n You are deleting a middle node");
            delptr->prev->next = delptr->next;
            delptr->next->prev = delptr->prev;
            free(delptr); scount--;
        }
        
        return head;
    }//end of else
    
}//end of deleteAny function

int main()
{
    head = NULL;
    tail = NULL;
    searchptr = NULL;
    
    int choice = 0;
    LLDemoOptions();
    
    while(1)
    {
        printf("\nEnter your choice(0-10,-1 to quit):");
        scanf("%d",&choice);
        
        if(choice == -1)
            break;
        //Caution: DONOT forget to write 'break' for every case!
        switch(choice)
        {
            case 0:
                LLDemoOptions();
                break;
            case 1:
                printf("\nPlease enter a number to search:");
                scanf("%d",&srollno);
                searchptr = searchStudent(head, srollno);
                if(searchptr != NULL)
                {
                    printf("\nStudent with RollNo %d found. Name is %s",searchptr->rollno, searchptr->name);
                }
                else
                {
                    printf("\nStudent with RollNo %d not found.",srollno);
                }
                break;
                
            case 2:
                printf("\nEnter the Student RollNo ");scanf("%d",&srollno);
                printf("\nEnter the Student Name "); scanf("%s", sname);
                head = insertAny(head);
                break;
                
            case 3:
                printThreeBDetails(head);
                break;
                
            case 4:
                printf("\nEnter the Student RollNo to delete ");scanf("%d",&srollno);
                head = deleteAny(head,srollno);
                break;
                
        }//end switch
        
    }//end while
    
}//end main






