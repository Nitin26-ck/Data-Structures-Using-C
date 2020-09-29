#include<stdio.h> 
#define SIZE 3

struct mySem
{ 

char course[20]; int credits;
} sem[SIZE]; 

int main()
{
	
		
	for(int i = 0; i<SIZE; i++)
	{
	printf("\n Enter your name of course#%d ", i+1); 
	scanf("%s", sem[i].course); 
	printf("\n Enter your course credits"); 
	scanf("%d", &sem[i].credits); 	
	}
	
	printf("\n The details of array of structure are"); 
	for(int i = 0; i<SIZE; i++)
	{
	printf("\n Course#%d name is %s and its Credits  is %d ", i+1, sem[i].course, sem[i].credits); 
	}
	
} 