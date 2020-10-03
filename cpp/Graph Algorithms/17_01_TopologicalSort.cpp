// Author : rishab__1128
#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000

vector<int>adj[SIZE];
vector<int>ans;
int indec[SIZE];

void kahn(int n)
{
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
        if(indec[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front();
        ans.push_back(x);
        q.pop();
        for(auto child: adj[x])
        {
            indec[child]--;
            if(indec[child]==0)
                q.push(child);
        }
    }
    cout<<"\nTopological Sort : ";
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
    // std::ios::sync_with_stdio(false);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
    
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indec[y]++;
    }
    kahn(n);

    return 0;
}
