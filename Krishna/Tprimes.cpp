#include <bits/stdc++.h>
using namespace std;

const int max_num = 1000000;
int primes[max_num + 1];

void sieve()
{
    long long int a;
    primes[0] = -1;
    primes[1] = -1;
    for(long long int i = 2; i <= max_num; ++i)
    {
        primes[i] = 1;
    }

    for(long long int i = 2; i * i  < max_num; ++i)
    {
        if(primes[i])
        {
            for(long long int j = i * i; j <= max_num; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}


int main()
{
    sieve();
    long long int n, a, p, q;
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        cin>>a;
        if(a==1)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            p = ceil(sqrt(a));
            q = floor(sqrt(a));

            if(p == q)
            {
                if(primes[p])
                {
                    cout<<"YES"<<"\n";
                }
                else
                {
                    cout<<"NO"<<"\n";
                }
            }   
            else
            {
                cout<<"NO"<<"\n";
            }
        }         
    }
    return 0;
}