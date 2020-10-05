// Program to check if a given linked list of strings
// form a palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Link list node */
typedef struct Node
{
    char data[20];
    struct Node* next;
}Node;

int isPalindromeUtil(char str[])
{
    printf("\n Inside is PalindromeUtil");
    int length = (int)strlen(str);
    printf("\n String length is %d", length);
    
    for (int i=0; i<length/2; i++)
        if (str[i] != str[length-i-1])
            return 0;
    
    return 1;
}


int isPalindrome(Node *node)
{
    printf("\n Inside isPalindrome");
    
    printf("\n%s-> ", node->data);
   int length = (int)strlen(node->data);
    printf("\n String length of node->data is %d", length);
    
    char *str = (char *)malloc(sizeof(length));
     printf("\n String length of str is %d", (int)strlen(str));
    
    
   
    
    while (node != NULL)
    {
        
        strcat(str,node->data);
        node = node->next;
    }
    printf("\n %s",str);
    
    
}
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%s-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


Node * newNode(char *str)
{
    printf("\n..in NewNode function");
    Node *new_node = (Node *)malloc(sizeof(Node));
    printf("\n..After malloc");
    strcpy(new_node->data,str);
    printf("\n..%s", new_node->data);
    new_node->next = NULL;
    return new_node;
}


int main()
{
    Node *head = newNode("ma");
    head->next = newNode("lay");
    head->next->next = newNode("a");
    head->next->next->next = newNode("l");
    head->next->next->next->next = newNode("am");
    
    printf("\n..Calling isPalindrome function");
    int palin = isPalindrome(head);
    if(palin ==1) printf("\ntrue\n");
    else printf("\nfalse\n");
    
   
    
    return 0;
}

