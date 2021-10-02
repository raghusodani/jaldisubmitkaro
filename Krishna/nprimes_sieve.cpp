#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, a; 
    cin>>n;
    int arr[n + 1];
    arr[0] = -1;
    arr[1] = -1;
    for(long long int i = 2; i <= n; ++i)
    {
        arr[i] = 1;
    }

    for(long long int i = 2; i * i  < n; ++i)
    {
        if(arr[i])
        {
            for(long long int j = i * i; j <= n; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    for(long long int i = 0; i <= n; ++i)
    {
        cout<<i<<" "<<arr[i]<<"\n";
    }
    return 0;
}