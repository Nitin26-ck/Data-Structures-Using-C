#include<stdio.h>
int main()
{
	int n;
	long int factorial;
	printf("enter the value of n\n");
	scanf("%d",&n);
	factorial=fact(n);
	printf("the factorial of %d is %ld",n,factorial);
	return 0;
}
int fact(int n)
{
	if(n==0)
		return 1;
	else
		return(n*fact(n-1));
}

