#include<bits/stdc++.h>
using namespace std;

#define Min(x,y,z)  min(x,min(y,z))

int editDistance(string s1, string s2)
{
	int m=s1.size();
	int n=s2.size();

	int dp[m+1][n+1]; //dp[i][j]:=Edit distance b/w strings of len i & j


	//Base Case:
	//(1)If m==0 then dp[0][j]=j(Inserting j char's in s1);
	//(2)If n==0 then dp[i][0]=i(Deleting i char's from s1);

	for(int j=0; j<=n; j++)
	{
		dp[0][j]=j;
	}

	for(int i=0; i<=m; i++)
	{
		dp[i][0]=i;
	}

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(s1[i-1]!=s2[j-1])
				dp[i][j]=Min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1;
			else
				dp[i][j]=dp[i-1][j-1];			
		}
	}

	return dp[m][n];

}

int main()
{
	/*std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/

	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1,s2) << endl;

}