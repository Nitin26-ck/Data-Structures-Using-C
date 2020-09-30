#include<stdio.h> 
#define SIZE 3

struct Details 
{ 
char name[20]; int age;
struct Details *link; 
} myClass; 

int main()
{
	
	
	printf("\n Enter your name "); 
	scanf("%s", myClass.name); 
	printf("\n Enter your age "); 
	scanf("%d", &myClass.age); 
	
	printf("\n Enter your Link - name "); 
	scanf("%s", link->name); 
	printf("\n Enter your Link -age "); 
	scanf("%d", &link->age); 
	
	printf("\n The details of one structure are"); 
	printf("\n Name is %s and age is %d ", myClass.name, myClass.age); 
	printf("\n Link : Name is %s and age is %d ", link->name, link->age); 

}



