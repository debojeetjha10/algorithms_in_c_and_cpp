//Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR  = 256;
const int MOD = 1000000007;

int CountSubseq(string s, int n)
{
	vector<int>last(MAX_CHAR,-1);

	int dp[n+1]; //dp[i] := The no. of distinct subseq's of len. i
	dp[0]=1;

	for(int i=1; i<=n; i++)
	{
		dp[i]=2*dp[i-1];
        
        if(dp[i]>=MOD)
            dp[i]-=MOD;        

		if(last[s[i-1]]!=-1)
        {
			dp[i]-=dp[last[s[i-1]]];
            if(dp[i]<0)
                dp[i]+=MOD;
        }

		last[s[i-1]]=i-1;
	}

	return dp[n]%MOD;
}

void solve()
{
	string s;
	cin>>s;

	int n=s.size();

	int ans=CountSubseq(s,n);

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