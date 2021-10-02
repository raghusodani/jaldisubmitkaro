#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    
    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    int l = 0, r = n - 1;
    int i = 0;
    int temp;
    while(i <= r)
    {
        if(a[i] == 0)
        {
            if(i <= l)
            {
                ++i;
                ++l;
            }
            else
            {
                temp = a[i];
                a[i] = a[l];
                a[l] = temp;
                ++l;
            }
        }
        else if(a[i] == 2)
        {
            temp = a[i];
            a[i] = a[r];
            a[r] = temp;
            --r;
        }
        else if(a[i] == 1)
        {
            ++i;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout<<a[i];
    }

    return 0;
}