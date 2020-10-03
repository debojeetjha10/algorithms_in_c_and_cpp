//Author: rishab_1128
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005

int dp[1005][1005];

int func(char*S,  char*V, int m, int n)
{
	if(m==0)
		return MAX;

	if(n==0)
		return 1;

	if(dp[m][n]!=-1)
		return dp[m][n];

	int k;
	for(k=0; k<n; k++)
	{
		if(V[k]==S[0])
			break;
	}

	if(k==n)
		return 1;

	 return dp[m][n]=min(func(S+1, V, m-1, n), 1 + func(S+1, V+k+1, m-1, n-k-1)); 
}

int solve(string S,string V)
{
	int m=S.size(),n=V.size();

	char A[m], B[n];

	for(int i=0; i<m; i++)
	{
		A[i]=S[i];
	}

	for(int i=0; i<n; i++)
	{
		B[i]=V[i];
	}

	memset(dp,-1,sizeof(dp));

	int ans=func(A,B,m,n);
	return ans;

}

void solve()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;	
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
