#include<stdio.h>
#include<ctype.h>
void move(int,char,char,char);
int main()
{
	int n;
	printf("enter the value of n\n");
	scanf("%d",&n);
	char source,destination,temp;
	source='a';
	destination='c';
	temp='b';
	move(n,'a','c','b');
	return 0;
}
void move(int n,char source,char destination,char temp)
{
	if(n==1)
	{
		
		printf("disc %d is moved from source %c to destination %c\n",n,source,destination);
		return;
	}
	
	
	move(n-1,source,temp,destination);
	printf("disc %d is moved from source %c to destination %c\n",n,source,destination);
	move(n-1,temp,destination,source);
	
}
