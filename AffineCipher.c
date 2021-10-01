#include<stdio.h>

//function to encrypt the message
char* encrypt(char s[],int a,int b){
	char str[100]="";//intializing string to store the encrypted message
	int i = 0;
    for (i = 0; i<strlen(s); i++)//traversing through the string to encrypt it
    {
        if(s[i]!=' '){ //if the character is space then it would be kept as it is in the encrypted message
        	char ch  = ((((a * (s[i]-'A') ) + b) % 26) + 'A'); //encrypting the message using the equation (ax+b)mod m 
        	strncat(str,&ch, 1);//concatenating this character with the orignal string
		} 
        else{
        	strncat(str,&s[i], 1);//space character in orignal string added as it is to the encrypted string 
		}    
    }
	return str;
}

//function to find the modular inverse of a number with 26
int modular_inverse(int a)
{
	int m = 26;//taking modular inverse of a with 26
    int y = 0, x = 1; 
    while (a > 1) {
        int q = a / m;//quotient
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += 26;  
    return x;
}

//function to decrypt the message
char* decrypt(char s[],int a, int b){ 
	char str[100]="";//intializing string to store the decrypted message
	int a_inverse = modular_inverse(a);//finding modular inverse of 'a' using the extended euclidean algorithm
//	printf("%d",a_inverse);
	int i;
    for (i = 0; i < strlen(s); i++)
    {
        if(s[i]!=' '){
        	char ch = (((a_inverse * ((s[i]+'A' - b)) % 26)) + 'A');//decrypting the message using the equation a^-1(x-b)mod m 
        	strncat(str,&ch, 1); //concatenating this character with the orignal string 
		}
        else{
        	strncat(str,&s[i], 1); //space character in orignal string added as it is to the encrypted string
		}
    }
	return str;
}

//function to find the gcd of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

//main
int main()
{
	int i,a,b;
	char str[100];
	printf("Enter the plain text(in capital letters) : ");
	gets(str);
	printf("Enter the key values a & b : ");
	scanf("%d %d",&a,&b);
	if(gcd(a,26)==1){ //check if a and m(i.e. 26) are coprime, so that the modular inverse of 'a' exists
		char encStr[100],decStr[100];//strings to store the encrypted and decrypted message
		strcpy(encStr,encrypt(str,a,b));
		printf("Plain text after encryption : %s\n",encStr);
		strcpy(decStr,decrypt(encStr,a,b));
		printf("Plain text after decryption : %s\n",decStr);
	}
	else{
		printf("Key is invalid!!\n"); // if a and m are not coprime, print "Invalid key"
	}
	return 0;
}


















