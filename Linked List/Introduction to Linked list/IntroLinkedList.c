
#include <stdio.h>
#include<stdlib.h>
struct Hotel
{
    char item[20];
    int qty;
    float price;
    struct Hotel *link;
}*ptrHotel, *head;
int main()
{
    ptrHotel = NULL;
    printf("\n Enter the number of items"); int num;
    scanf("%d", &num);
    ptrHotel = (struct Hotel *)malloc(num * sizeof(struct Hotel));
    head = ptrHotel;
    for(int i = 0; i<num; i++)
    {
            printf("\n Enter name of item#%d ", i+1);
            scanf("%s", ptrHotel->item); //Also works: scanf("%s", current->item);
            printf("\n Enter price of item#%d ", i+1);
            scanf("%f", &ptrHotel->price);//Also works: scanf("%f", current->price);
            printf("\n Enter quantity of item#%d ", i+1);
            scanf("%d", &ptrHotel->qty);//Also works: scanf("%d", current->qty);
            ptrHotel->link = ptrHotel +1;
            ptrHotel = ptrHotel->link;

    }
    for(int j = 0; j<num; j++)
    {
        printf("\nItem #%d details are:", j+1);
        printf("\n Item name : %s, Item Price %f, Item Qty %d", head->item, head->price,head->qty);
        head = head->link;
        
    }
    printf("\n");
}

