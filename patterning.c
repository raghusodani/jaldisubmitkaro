#include<stdio.h>
void pattern1()
{
	int m=1;
	for(int i=5;i>=0;i--)
	{
		for(int x=0;x<=m;x++)
			printf(" ");
		m++;
		for(int j=1;j<=i;j++)
			printf("%d",j);
		for(int k=i-1;k>0;k--)
			printf("%d",k);
		printf("\n");
	}
}
void pattern2()
{
	int space=0;
	for(int i=5;i>0;i--)
	{
		for(int j=0;j<i;j++)
			printf("*");
		for(int k=0;k<space;k++)
			printf(" ");
		for(int x=0;x<i;x++)
			printf("*");
		printf("\n");
		space+=2;
	}
}
int main()
{
	pattern1();
	pattern2();
	return 0;
}
