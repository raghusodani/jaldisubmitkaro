#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adjl[n+1];
    bool vis[n+1];
    for(int i=0; i<=n; i++)
        vis[i] = 0;

    for(int i=1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<endl;
        for(int i=0; i<adjl[node].size(); i++)
        {
            if(!vis[adjl[node][i]])
            {
                vis[adjl[node][i]] = 1;
                q.push(adjl[node][i]);
            }
        }
    }
    return 0;
}