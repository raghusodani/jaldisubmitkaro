#include <stdio.h>
#include <conio.h>
void main() {
	char *a;
	int i,len,flag=0;
	clrscr();
	printf("\nENTER A STRING: ");
	gets(a);
	len=strlen(a);
	for (i=0;i<len;i++) {
		if(a[i]==a[len-i-1])
		     flag=flag+1;
	}
	if(flag==len)
	             printf("\nTHE STRING IS PALINDROM"); else
	             printf("\nTHE STRING IS NOT PALINDROM");
	getch();
}