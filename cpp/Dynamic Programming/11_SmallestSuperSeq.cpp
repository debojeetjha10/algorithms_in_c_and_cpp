//Author: rishab_1128
#include<bits/stdc++.h>
using namespace std;

int dp[51][51]; 

//Using Recursion & Memoization
int func1(char str1[], int len1, char str2[], int len2, int i, int j)
{
	if(str1[i]=='\0')
		return len2;
	if(str2[j]=='\0')
		return len1;

	if(dp[i][j]!=-1)
		return dp[i][j];

	if(str1[i]==str2[j])
		return dp[i][j]=1+func1(str1,len1-1,str2,len2-1,i+1,j+1);
	else
		return dp[i][j]=1+min(func1(str1,len1-1,str2,len2,i+1,j),func1(str1,len1,str2,len2-1,i,j+1));
}

//Using Tabulization(Iterative Method)
int func2(char str1[], int len1, char str2[], int len2)
{
	int DP[len1+1][len2+1];

	//Filling last row
	int k=len2;
	for(int j=0; j<=len2; j++)
	{
		DP[len1][j]=k;
		k--;
	}

	//Filling last col
	int j=len1;
	for(int i=0; i<=len1; i++)
	{
		DP[i][len2]=j;
		j--;
	}

	//Filling the rest of the table in bottom up manner
	for(int i=len1-1; i>=0; i--)
	{
		for(int j=len2-1; j>=0; j--)
		{
			if(str1[i]==str2[j])
				DP[i][j]=1+DP[i+1][j+1];
			else
				DP[i][j]=1+min(DP[i][j+1],DP[i+1][j]);
		}
	}

	return DP[0][0];
}


int smallestSuperSequence(char str1[], int len1, char str2[], int len2) 
{
	memset(dp,-1,sizeof(dp));
	int ans=func2(str1,len1,str2,len2);
	return ans;
}

void solve()
{
	char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
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
