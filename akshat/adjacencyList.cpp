#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjl(n+1, vector<int>());
    for(int i=0; i<m; i++)
    {   int x, y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<adjl[i].size(); j++)
            cout<<adjl[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}