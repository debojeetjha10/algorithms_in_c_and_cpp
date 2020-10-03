// Author: rishab_1128
#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000

vector<int>adj[SIZE];
vector<bool>vis;
vector<int>ans;

void dfs(int v)
{
    vis[v]=true;
    for(auto child: adj[v])
    {
        if(!vis[child])
            dfs(child);
    }
    ans.push_back(v);
}

void topo_sort(int n)
{
    vis.assign(n,false);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    reverse(ans.begin(),ans.end());
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    topo_sort(n);
    cout<<"\nTopological Sort : ";
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}