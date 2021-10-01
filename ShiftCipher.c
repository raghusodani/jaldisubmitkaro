#include<stdio.h>
char* encrypt(char s[],int key)
{
	char str[100]="";
 	int i = 0;
 	for(i = 0;i<strlen(s);i++){
 			if(s[i]==' '){
				strncat(str,&s[i], 1);
			}
			else if(isupper(s[i])){
 				char ch = (s[i]+key-65)%26 + 65;
 				strncat(str,&ch, 1);
			}
 			else{
 				char ch = (s[i]+key-97)%26 + 97;
 				strncat(str,&ch, 1);
			}
	}
	return str;
}
char* decrypt(char s[],int key)
{
	char str[100]="";
 	int i = 0;
 	for(i = 0;i<strlen(s);i++){
 			if(s[i]==' '){
 				strncat(str,&s[i], 1);	
			}
			else if(isupper(s[i])){
 				char ch;
 				if((s[i]-key-65)%26<0){
 					ch = (s[i]-key-65)%26 + 65 + 26;
				}
 				else{
 					ch = (s[i]-key-65)%26 + 65;
				}	
 				strncat(str,&ch, 1);
			}
 			else{
 				char ch;
 				if((s[i]-key-97)%26<0){
 					ch = (s[i]-key-97)%26 + 97 + 26;	
				} 	
 				else{
 					ch = (s[i]-key-97)%26 + 97;	
				}	
 				strncat(str,&ch, 1);
			}
	}
	return str;
}
int main()
{
	int i,key;
	char str[100];
	printf("Enter the plain text : ");
	gets(str);
	printf("Choose a secret key between 0 - 25 : ");
	scanf("%d",&key);
	char encStr[100],decStr[100];
	strcpy(encStr,encrypt(str,key));
	printf("Plain text after encryption : %s\n",encStr); 
	strcpy(decStr,decrypt(encStr,key));
	printf("Plain text after decryption : %s\n",decStr); 
	return 0;
}
