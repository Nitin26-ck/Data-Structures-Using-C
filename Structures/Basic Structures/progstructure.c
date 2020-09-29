#include<stdio.h>
#include<string.h>
{
	struct student;
	{
		char name[50];
		int roll;
		float physics;
		float chemistry;
		float maths;
	};
}
		
	 stud[3];
int main()
{
	int i;

	printf("enter the info of students\n");
	for(i=0;i<3;i++)
	{
		stud[i].roll=i+1;
		printf("enter the roll number\n",stud[i].roll);
		printf("enter name\n");
		scanf("%s",stud[i].name);
		printf("enter physics marks\n");
		scanf("%f",&stud[i].physics);
		printf("enter chemistry marks\n");
		scanf("%f",&stud[i].chemistry);
		printf("enter maths marks\n");
		scanf("%f",&stud[i].maths);
		printf("\n");
	}
	printf("displaying the required info\n");
	for(i=0;i<3;i++)
	{
		printf("roll number=%d\n",i+1);
		printf("name\n");
		puts(stud[i].name);
		printf("physics marks=%f\n",stud[i].physics);
		printf("chemistry marks=%f\n",stud[i].chemistry);
		printf("maths marks=%f\n",stud[i].maths);
		printf("\n");
	}
	return 0;
}
