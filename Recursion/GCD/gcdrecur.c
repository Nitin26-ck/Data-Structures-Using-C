#include<stdio.h>
int gcd(int n1,int n2);
int main()
{
	int n1,n2;
	printf("enter n1 and n2\n");
	scanf("%d%d",&n1,&n2);
	printf("gcd of %d and %d is %d\n",n1,n2,gcd(n1,n2));
	return 0;
}
int gcd(int n1,int n2)
{
	if(n2!=0)
		return gcd(n2,n1%n2);
	else
		return n1;
}

