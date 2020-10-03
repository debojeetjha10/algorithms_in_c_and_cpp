// Author: rishab_1128
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define SIZE 200005
#define all(v) v.begin(),v.end()
const int MOD  = 1000000007;

vector<int>adj[SIZE];
bool vis[SIZE];
int dp[SIZE];  //dp[i] stores the size of the subtree at vertex i (including vertex i)

int dfs(int node)
{
	vis[node]=1;
    int curr_size=1;
    for(auto child : adj[node])
    {
        if(!vis[child])
        {
            curr_size+=dfs(child);
        }
    }
    dp[node]=curr_size;
    return dp[node];
}

void solve()
{
	int n;
	cin>>n;
	for(int i=0; i<n-1; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int i=1; i<=n; i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	

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