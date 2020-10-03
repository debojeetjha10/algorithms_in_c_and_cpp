#include<bits/stdc++.h> 
using namespace std;

int MOD = 1000000007;

//Application of Catalan Numbers
//T.C using recursion =O(n^n)
//T.C using DP=O(n^2)

int countBST( int n)
{
	int dp[n+1]; //dp[i] := count of structurally unique BST's with i nodes
	
	dp[0]=1;
	dp[1]=1;

	for(int i=2; i<=n; i++)
	{
        dp[i]=0;
		for(int j=0; j<i; j++)
		{
            long res = dp[j] * 1l * dp[i-j-1];
            int temp = (int)(res%MOD);
			dp[i]=(dp[i]+temp)%MOD;
		}
	}

	return dp[n]%MOD;
 
}

int main()
{
	std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
