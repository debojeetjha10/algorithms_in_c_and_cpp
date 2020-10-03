// Author: rishab_1128
//Cycle Detection in a Directed Graph using DFS

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define SIZE 100001
const int MOD  = 1000000007;

vector<int>adj[SIZE];
bool vis[SIZE];
bool rec[SIZE];

bool dfs_detect_cycle(int node)
{
	if(!vis[node])
	{
		vis[node]=1;
		rec[node]=1;
		for(int child: adj[node])
		{
			if(!vis[child]&&dfs_detect_cycle(child))
				return true;
			else if(rec[child])
				return true;
		}
	}
	rec[node]=0;
	return false;
}

void solve()
{
    int n,m;
	cin>>n>>m;
	//Creating the adjacency list
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	memset(vis,0,sizeof(vis));
	memset(rec,0,sizeof(rec));

	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			int flag=dfs_detect_cycle(i);
			if(flag)
			{
				cout<<"CYCLE DETECTED"<<endl;
				return;
			}
			else
			{
				cout<<"NO CYCLE DETECTED"<<endl;
				return;
			}
		}
	}
}

int32_t main()
{
    /*std::ios::sync_with_stdio(false);
     #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif*/

	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}

	return 0;
}