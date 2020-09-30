#include<stdio.h> 
#define SIZE 3
#include <stdlib.h>

struct Details 
{ 
char name[20]; int age;

}; 

int main()
{
	struct Details * myClass; 
	myClass = (struct Details *) malloc(sizeof(struct Details));
	// OR write like this: struct Details * myClass = (struct Details *) malloc(sizeof(struct Details)); 
	printf("\n Enter your name "); 
	scanf("%s", myClass->name); 
	printf("\n Enter your age "); 
	scanf("%d", &myClass->age); 
	
	
	
	printf("\n The details of one structure are"); 
	printf("\n Name is %s and age is %d ", myClass->name, myClass->age); 
	
}
