//Author-rishab_1128

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[41];

int balancedBTs(int h) 
{
	if(h==0||h==1)
		return 1;

	if(dp[h]!=0)
		return dp[h];

	int x=balancedBTs(h-1);
	int y=balancedBTs(h-2);

	long res1 = (long)x*x;
	long res2 = (long)x*y*2;

	int ans1 = (int)(res1%mod);
	int ans2 = (int)(res2%mod);

	int ans = (ans1+ans2)%mod;

	return dp[h]=ans;
}

void solve()
{
	int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
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

