// Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;

int vis[100000];
vector<int> adj[100000];

bool dfs_cycle_detect(int node, int parent)
{
	vis[node]=1;

	for(auto child: adj[node])
	{
		if(vis[child]==0)
		{
			if(dfs_cycle_detect(child,node))
				return true;
		}
		else
		{
			if(child!=parent)
				return true;
		}
	}

	return false;
}

void solve()
{
	int V,E;
	cin>>V>>E;

	for(int i=0; i<E; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(dfs_cycle_detect(1,-1))
		cout<<1<<endl;
	else
		cout<<0<<endl;

}

int main()
{
	std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
    return 0;

}