//Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;

int func(bool*arr, int n, int open, int close, int**dp)
{
	if(arr[0])
	{
		return 0;
	}

	if(dp[open][close]>=0)
	{
		return dp[open][close];
	}

	if(close>n||open>n)
	{
		return 0;
	}

	if(close==n&&open==n)
	{
		return 1;
	}

	int ans;
	if(close==open||arr[close+open+1])
	{
		ans= func(arr, n, open+1, close, dp);
	}

	else if(open==n)
	{
		ans= func(arr, n, open, close+1, dp);
	}

	else
	{
		int option1=func(arr, n, open+1, close, dp);
		int option2=func(arr, n, open, close+1, dp);
		ans= option1+option2;
	}

	dp[open][close]=ans;
	return ans;
}

void solve()
{
	int n,k;
	cin>>n>>k;

	bool*arr=new bool[2*n+1];
	for(int i=0; i<=2*n; i++)
	{
		arr[i]=false;
	}

	for(int i=0; i<k; i++)
	{
		int ele;
		cin>>ele;
		arr[ele]=true;
	}

	int**dp=new int*[21];
	for(int i=0; i<=20; i++)
	{
		dp[i]=new int[21];
		for(int j=0; j<=20; j++)
		{
			dp[i][j]=-1;
		}
	}

	cout<<func(arr,n,0,0,dp)<<endl;


}

int main()
{
	std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
    return 0;
}