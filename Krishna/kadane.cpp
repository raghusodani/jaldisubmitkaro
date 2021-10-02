#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {-1, -2, -1, 4, 5};
    int dp[5];
    dp[0] = arr[0];
    for(int i = 1; i < 5; ++i)
    {
        if(arr[i] > dp[i - 1] + arr[i])
        {
            dp[i] = arr[i];
        }
        else
        {
            dp[i] = arr[i] + dp[i - 1];
        }

    }

    for(auto i: dp)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<*max_element(dp, dp + 5);
    cout<<"\n";
    return 0;
}