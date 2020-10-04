//Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;

bool SubsetSum(int n, int*values, int sum)
{
	bool**dp=new bool*[n+1];
	for(int i=0; i<=n; i++)
	{
		dp[i]=new bool[sum+1];
	}

	//Base Cases
	for(int j=0; j<=sum; j++)
	{
		dp[0][j]=0;
	}
	for(int i=0; i<=n; i++)
	{
		dp[i][0]=1;
	}

	for (int i = 1; i <= n; i++) 
	{ 
        for (int j = 1; j <= sum; j++) 
        { 
            if (j < values[i - 1]) 
                dp[i][j] = dp[i - 1][j]; 
            if (j >= values[i - 1]) 
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - values[i - 1]]; 
        } 
    }

    bool ans=dp[n][sum];

    //Delete dp array
    for(int i=0; i<=n; i++)
    {
    	delete[]dp[i];
    }
    delete[]dp;

    return ans;
	
}

//For Space Efficiency we can use a DP array with only 2 rows as DP[i] ONLY DEPENDS ON DP[i-1]
bool SubsetSum2(int n, int*values, int sum)
{
	bool**dp=new bool*[2];
	for(int i=0; i<=1; i++)
	{
		dp[i]=new bool[sum+1];
	}

	//Base Cases
	for(int j=0; j<=sum; j++)
	{
		dp[0][j]=0;
	}
	dp[0][0]=1;

	int flag=1;

	for (int i = 1; i <= n; i++) 
	{ 
        for (int j = 1; j <= sum; j++) 
        { 
            if (j < values[i - 1]) 
                dp[flag][j] = dp[flag^1][j]; 
            if (j >= values[i - 1]) 
                dp[flag][j] = dp[flag^1][j] || dp[flag^1][j - values[i - 1]]; 
        }
        flag^=1; 
    }

    bool ans=dp[flag^1][sum];

    //Delete dp array
    for(int i=0; i<=1; i++)
    {
    	delete[]dp[i];
    }
    delete[]dp;

    return ans;
	
}


void solve()
{
	int n;
	cin>>n;

	int*values=new int[n];
	for(int i=0; i<n; i++)
	{
		cin>>values[i];
	}

	int sum;
	cin>>sum;

	bool ans=SubsetSum2(n,values,sum);

	if(ans)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
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