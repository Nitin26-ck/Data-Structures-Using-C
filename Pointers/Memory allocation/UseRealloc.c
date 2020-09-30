#include <stdio.h>
#include <stdlib.h>
/*
 ptr and ptr_new share the same location for the 2 integers after realloc is used. This means the previous values used by ptr are overwritten.
 Realloc should be used when memory is allotted dynamically from the heap and NOT during static allocation.
 */
int main()
{
    int *ptr = (int *)malloc(sizeof(int)*2);
    int i;
    int *ptr_new;
    
    *ptr = 10;
    *(ptr + 1) = 20;
    
    ptr_new = (int *)realloc(ptr, sizeof(int)*3);
    printf("\n%d ", *(ptr_new));
    printf("\n%d ", *(ptr_new + 1));
    
    *(ptr_new + 2) = 300;
    for(i = 0; i < 3; i++)
        printf("\n%d ", *(ptr_new + i));
    
    
    *(ptr + 1) = 200;
    printf("\n%d ptr", *(ptr));
    printf("\n%d ptr + 1", *(ptr + 1));
    printf("\n%d ptr + 2", *(ptr + 2));
    
    *(ptr_new + 1) = 2000;
    printf("\n%d ptr_new", *(ptr_new));
    printf("\n%d ptr_new+1", *(ptr_new + 1));
    
    printf("\n%d ptr + 1", *(ptr));
    printf("\n%d ptr + 1", *(ptr + 1));
    
    printf("\n Bad use of realloc");
    int arr[2];
    //arr is statically allotted
    //myptr should be allotted via malloc or calloc for realloc to work
    
    int *myptr = arr;
    
    int *myptr_new;
    
    arr[0] = 10;
    arr[1] = 20;
    
    // incorrect use of new_ptr: undefined behaviour
    //myptr is having statically assigned address and not from heap.
    //Program will fail.
    myptr_new = (int *)realloc(myptr, sizeof(int)*3);
    *(myptr_new + 2) = 30;
    
    for(i = 0; i < 3; i++)
        printf("%d ", *(myptr_new + i));
    
    getchar();
    return 0;
}
