#include <bits/stdc++.h>
using namespace std;

int solve(string s1 ,string s2 ,int k , int dp[101][101][101] , int i , int j)
{

if(k==0)
return 0;

if(i==s1.length() || j==s2.length())
return INT_MIN;

if(dp[i][j][k]!=-1)
return dp[i][j][k];

int ans;

if(s1[i]==s2[j]){

ans = max(solve(s1,s2,k-1,dp,i+1,j+1) + int(s1[i]),max(solve(s1,s2,k,dp,i+1,j),solve(s1,s2,k,dp,i,j+1)));

}

else{

ans = max(solve(s1,s2,k,dp,i+1,j),solve(s1,s2,k,dp,i,j+1));

}

dp[i][j][k] = ans;

return ans;

}

int main()

{

int t;

cin >> t;

while(t--){

string s1;

string s2;

cin >> s1 >> s2;

int n;

cin >> n;

int dp[101][101][101];

memset(dp,-1,sizeof(dp));

int ans = solve(s1,s2,n,dp,0,0);

if(ans >= 0)

cout << ans << endl;

else

cout << 0 << endl;

}

return 0;

}