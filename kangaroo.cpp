#include<bits/stdc++.h>
using namespace std;
int main()
{   long long int yesorno(long long int,long long int,long long int,long long int);
    long long int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    yesorno(x1,v1,x2,v2);
    return 0;
}

long long int yesorno(long long int X,long long int V1,long long int Y,long long int V2)
{ 
long long int flag=0,sum1=0,sum2=0;
sum1=X+V1;
sum2=Y+V2;
if(sum1==sum2)
{
    flag=1;
}
while((sum1!=sum2)&&(sum1<1000000000)&&(sum2<1000000000))
{
    
    sum1+=V1;
    sum2+=V2;
    if(sum1==sum2)
    {
        flag=1;
        break;
    }
}
if(flag==1)
{
cout<<"YES";
}
if(flag==0)
{
    cout<<"NO";
}     

return sum1,sum2;
}
