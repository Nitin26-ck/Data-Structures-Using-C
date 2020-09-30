
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main()
{
    int *arrmalloc, *arrcalloc;
    
    // malloc() allocate the memory for 5 integers
    // containing garbage values
    arrmalloc = (int *)malloc(SIZE * sizeof(int)); // 5*4bytes = 20 bytes
    
    printf("\n Address of array dynamically allotted  by malloc is %d", arrmalloc);
    printf("\nAfter Malloc -- prints junk values of the memory allotted. Does not initialize");
    for(int i = 0; i<SIZE; i++)
    {
     printf("\n Position# is %d", i);
     printf("\n Address-> %d Value is %d",arrmalloc,*arrmalloc);
        arrmalloc = arrmalloc+1;
    }
    
    
    // Deallocates memory previously allocated by malloc() function
    //free( arr );
    
    
    
    // calloc() allocate the memory for 5 integers and
    // set 0 to all of them
    arrcalloc = (int *)calloc(SIZE, sizeof(int));
    printf("\n\n Address of array dynamically allotted by calloc is %d", arrcalloc);
    printf("\nAfter Calloc -- prints zero values for the memory allotted. Initializes allotted memory");
    
    for(int i = 0; i<SIZE; i++)
    {
    printf("\n Position# is %d", i);
    printf("\n Address-> %d Value is %d",arrcalloc, *arrcalloc);
        arrcalloc = arrcalloc+1;
    }
    
    printf("\n");
    // Deallocates memory previously allocated by calloc() function
    //free(arr);
    
    
    return(0);
}
