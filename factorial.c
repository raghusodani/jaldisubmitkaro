#include <stdio.h>

int fact(int x)
{
    if(x>1)
    x=x*fact(x-1);
    return x;
}

int main()
{
    int num=0;
    printf("Enter the Number for factorial :");
    scanf("%d",&num);
    printf("The value of factorial of %d is : %d",num,fact(num));
    return 0;
}
