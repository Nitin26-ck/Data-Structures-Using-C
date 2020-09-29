#include<stdio.h> 
#define SIZE 3

struct myDetails 
{ 

char name[20]; int age;
} me; 



int main()
{
	
	printf("\n Enter your name "); 
	scanf("%s", me.name); 
	printf("\n Enter your age "); 
	scanf("%d", &me.age); 
	
	printf("\n The details of one structure are"); 
	printf("\n Name is %s and age is %d ", me.name, me.age); 
	
	
	
} 