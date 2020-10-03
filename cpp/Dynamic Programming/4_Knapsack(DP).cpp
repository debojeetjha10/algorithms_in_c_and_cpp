//Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;

//Using Bottom-Up Approach
int dp[10000][10000];
int knapsack(int* weights, int* values, int n, int maxWeight)
{

	if(n==0||maxWeight==0)
		return 0;

	if(dp[n][maxWeight]!=0)
		return dp[n][maxWeight];

	if(weights[n-1]<=maxWeight)
	{
		dp[n][maxWeight]=max(knapsack(weights,values,n-1,maxWeight-weights[n-1])+values[n-1],knapsack(weights,values,n-1,maxWeight));
	}
	else
	{
		dp[n][maxWeight]=knapsack(weights,values,n-1,maxWeight);
	}
	return dp[n][maxWeight];
}

//Using Top-Down Approach
int knapsack2(int* weights, int* values, int n, int maxWeight)
{
	int DP[n+1][maxWeight+1];

	//Filling 0th row and 0th col
	for(int w=0; w<=maxWeight; w++)
	{
		DP[0][w]=0;
	}
	for(int i=0; i<=n; i++)
	{
		DP[i][0]=0;
	}

	int Weights[n+1],Values[n+1],j=1,k=1;
	for(int i=0; i<n; i++)
	{
		Weights[j]=weights[i];
		j++;
	}

	for(int i=0; i<n; i++)
	{
		Values[k]=values[i];
		k++;
	}

	for(int i=1; i<=n; i++)
	{
		for(int w=1; w<=maxWeight; w++)
		{
			if(Weights[i]<=w)
				DP[i][w]=max(DP[i-1][w],DP[i-1][w-Weights[i]]+Values[i]);
			else
				DP[i][w]=DP[i-1][w];

		}
	}

	return DP[n][maxWeight];
}

//This function also returns the sum of the weights of the item chosen along with the max value(i.e. DP + a bit of Backtracking)
pair<int,int> knapsack3(int* weights, int* values, int n, int maxWeight)
{
	int DP[n+1][maxWeight+1];

	//Filling 0th row and 0th col
	for(int w=0; w<=maxWeight; w++)
	{
		DP[0][w]=0;
	}
	for(int i=0; i<=n; i++)
	{
		DP[i][0]=0;
	}

	int Weights[n+1],Values[n+1],j=1,k=1;
	for(int i=0; i<n; i++)
	{
		Weights[j]=weights[i];
		j++;
	}

	for(int i=0; i<n; i++)
	{
		Values[k]=values[i];
		k++;
	}

	for(int i=1; i<=n; i++)
	{
		for(int w=1; w<=maxWeight; w++)
		{
			if(Weights[i]<=w)			
				DP[i][w]=max(DP[i-1][w],DP[i-1][w-Weights[i]]+Values[i]);			
			else
				DP[i][w]=DP[i-1][w];
		}
	}

	int maxvalue=DP[n][maxWeight];
	int minweight=0;
	for(int i=0;i<=maxWeight;i++)
	{
		if(DP[n][i]==maxvalue)
		{
			minweight=i;
			break;
		}
	}

	return {minweight,maxvalue};
}

void solve()
{

	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
	cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
	cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack2(weights, values, n, maxWeight);

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