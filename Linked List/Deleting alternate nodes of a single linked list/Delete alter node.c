#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}; struct node *head=NULL,*newnode,*ptr,*temp,*prev,*node;

void ins_end(){
	newnode=(struct node*)malloc(sizeof(struct node*));
		printf("enter the data to be inserted\n");
		scanf("%d",&newnode->data);
			if (head==NULL){
		newnode->link=NULL;
		head=newnode;
	} else {
		temp=head;
		while(temp->link!=NULL){
			temp=temp->link;
		} temp->link=newnode;
		 newnode->link=NULL;
	}
} void delete_alt() 
{ 
    if (head == NULL) 
       {
       	printf("nothing to delete\n");
	   }

    prev = head; 
    node = head->link; 
  
    while (prev != NULL && node != NULL) 
    {
        prev->link = node->link; 

        free(node); 

        prev = prev->link; 
        if (prev != NULL) 
            node = prev->link; 
    } 
} 
 void display(){
	if(head==NULL){
		printf("\nempty list\n\n");
	} else { temp=head;
		while(temp!=NULL){
			printf("\n%d\n",temp->data);
			temp=temp->link;
		}
	}
}
	int main(){ int ch; while (1) {

	printf("\n\n1.display\n2.insert in the end\n3.del alternate\n0.exit\n\n");
	scanf("%d",&ch);
	switch (ch){
		case 1: display();break;
		case 2: ins_end();break;
		case 3:delete_alt();break;
		case 0:exit(0);
	
	}
	
}}