#include<stdio.h>
#include<conio.h>
void enter();
void zone();
void mapping();
void seg();

void enter()
{
int b,nb,za,zb,zc,zd,ze;
printf("YOU HAVE TO ENTER AN APPROXIMATE AMOUNT OF GARBAGE IN YOUR HOUSE.\n");
printf("ENTER THE AMOUNT OF BIODEGRADABLE WASTE :");
scanf("%d",&b);
printf("\nENTER THE AMOUNT OF NON-BIODEGRADABLE WASTE :");
scanf("%d",&nb);
printf("YOUR CITY IS DIVIDED INTO 5 ZONES...\n ");
printf("ENTER THE NUMBER OF HOUSES IN ZONE A:");
scanf("%d",&za);
printf("ENTER THE NUMBER OF HOUSES IN ZONE B:");
scanf("%d"&zb);
printf("ENTER THE NUMBER OF HOUSES IN ZONE C:");
scanf("%d",&zc);
printf("ENTER THE NUMBER OF HOUSES IN ZONE D:");
scanf("%d",&zd);
printf("ENTER THE NUMBER OF HOUSES IN ZONE E:");
scanf("%d",&ze);
}
void zone()
{
int i,t,ar[50],temp;
t=(b+nb)*(za);
int gc=600;
int n;
n=t/gc;
printf("ENTER THE NUMBER OF HOUSES IN THE LOCALITY OF YOUR ZONE:\n");
for(i=0;i<n;i++)
{
 scanf("%d",ar[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(ar[j]>ar[i])
{
temp=ar[j];
ar[j]=ar[i];
ar[i]=temp;
}
}
}
for(i=0;i<n;i++)
{
printf("THE GARBAGE CANS WEIGHTS ARE AS FOLLOWS %d\n",ar[i]*(b+nb));
}
}

void mapping()
{
int zone1,D1,D2,a[100][100],m,n;
D1=a[50][99];
D2=a[0][99];
printf("CONSIDERING ZONE 1 ,ENTER ITS APPROXIMATE CENTRE");
scanf("%d %d",&m,&n);
zone1=a[m][n];
dist1=(((m-50)*(m-50))+((n-99)*(n-99)))^(0.5);
dist2=((m*m)+((n-99)*(n-99)))^(0.5);
if(dist1>dist2)
{
printf("GARBAGE IS DUMPED AT DUMPYARD NO.2");
}
else
{
printf("GARBAGE IS DUMPED AT DUMPYARD NO.1");
}
}

void seg()
{





