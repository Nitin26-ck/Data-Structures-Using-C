
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main()
{
    int *arrmalloc, *arrcalloc;
    
    // malloc() allocate the memory for 5 integers
    // containing garbage values
    arrmalloc = (int *)malloc(SIZE * sizeof(int)); // 5*4bytes = 20 bytes
    //Comment below line and see the difference
    memset(arrmalloc, 0, SIZE * sizeof(int));
    printf("\n Address of array dynamically allotted  by malloc is %d", arrmalloc);
    printf("\nAfter Malloc -- prints clean zero initialized values of the memory allotted, because of memset after malloc");
    for(int i = 0; i<SIZE; i++)
    {
        printf("\n Position# is %d", i);
        printf("\n Address-> %d Value is %d",arrmalloc,*arrmalloc);
        arrmalloc = arrmalloc+1;
    }
    
    return(0);
}

