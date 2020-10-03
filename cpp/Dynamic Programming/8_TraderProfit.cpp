//Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;

int dp[100][100][2];

int func(int*stock, int n, int k, int ongoing_trans)
{
	//Base Case
	if(n<=0)
		return 0;

	if(dp[n][k][ongoing_trans]!=0)
		return dp[n][k][ongoing_trans];

	if(ongoing_trans)
	{
		//Ignore the element
		int op1=func(stock+1,n-1,k,1);

		//Sell that element
		int op2=func(stock+1,n-1,k-1,0)+stock[0];

		dp[n][k][ongoing_trans]=max(op1,op2);
	}
	else
	{
		if(k>0)
		{
			//Ignore the element
			int op1=func(stock+1,n-1,k,0);

			//Buy that element
			int op2=func(stock+1,n-1,k,1)-stock[0];

			dp[n][k][ongoing_trans]=max(op1,op2);
		}
	}

	return dp[n][k][ongoing_trans];
}

void solve()
{
	int k,n;
	cin>>k>>n;

	int*stock=new int[n];
	for(int i=0; i<n; i++)
	{
		cin>>stock[i];
	}

	memset(dp,0,sizeof(dp));

	int ans=func(stock,n,k,0);

	//Delete stock array
	delete[]stock;

	cout<<ans<<endl;
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