//Author: rishab_1128

#include<bits/stdc++.h> 
using namespace std;
 
typedef string                         STR;
typedef long long                      ll;
typedef long double                    ld;
typedef unsigned long long             ull;
typedef vector<int>                    vi;
typedef priority_queue<int>            pqi;
typedef vector<ll>                     vll;
typedef vector<ull>                    vull;
typedef vector<STR>                    vs;
typedef vector<char>                   vc;
typedef pair<int,int>                  pii;
typedef pair<ll,ll>                    pll;
typedef pair<STR,int>                  psi;
typedef pair<char,ll>                  pcl;
typedef pair<int,STR>                  pis;
typedef vector<pii>                    vpii;
typedef vector<pll>                    vpll;
typedef vector<pcl>                    vpcl;
typedef map<int,int>                   mii;
typedef map<ll,ll>                     mll;
typedef map<STR,int>                   msi;
typedef map<char,int>                  mci;
typedef map<int,STR>                   mis;
typedef set<STR>                       ss;
typedef set<char>                      sc;
typedef set<int>                       si;
typedef set<ll>                        sll;
 
#define FF                             first
#define SS                             second
#define PB                             push_back
#define PF                             push_front
#define MP                             make_pair
#define all(a)                         (a).begin(), (a).end()
#define ps(x,y)                        fixed<<setprecision(y)<<x
#define setbits(x)                     __builtin_popcountll(x)
#define zrobits(x)                     __builtin_ctzll(x)
#define d2b(x,n)                       bitset<x>(n).to_string()
#define b2d(x,n)                       bitset<x>(n).to_ulong()
#define f(i,a,n)                       for(ll i=a; i<n; i++)                                      
#define f1(i,b,m)                      for(ll i=b; i<=m; i++)
#define f2(i,x,y)                      for(ll i=x; i>=y; i--)
#define fsort(a)                       sort(a.begin(), a.end())
#define rsort(a)                       sort(a.rbegin(), a.rend())
#define w(t)                           ll t; cin>>t; while(t--)
#define UB                             upper_bound
#define LB                             lower_bound
#define BS                             binary_search
#define EB                             emplace_back
#define Max(x,y,z)                     max(x,max(y,z))
#define Min(x,y,z)                     min(x,min(y,z))

const ll MOD     = 1000000007;
const ll SIZE    = 100000;
const int INF    = 0x3f3f3f3f;
const ll ll_INF  = 0x3f3f3f3f3f3f3f3f;
const ld PI      = acos(-1);
const ll MAXN    = numeric_limits<ll>::max();
const ll MAX     = 2000000;

//Using Recursion
int lcs1(char*s1,char*s2)
{
	//Base Cases
	if(s1[0]=='\0'||s2[0]=='\0')
		return 0;

	if(s1[0]==s2[0])
		return 1+lcs1(s1+1,s2+1);
	else
	{
		int op1=lcs1(s1,s2+1);
		int op2=lcs1(s1+1,s2);
		return max(op1,op2);
	}

}

//Using DP-Bottom Up Approach
int lcs2Helper(char*s1,char*s2,int m,int n,int**dp)
{
	if(m==0||n==0)
		return 0;
	if(dp[m][n]!=-1)
		return dp[m][n];

	int ans=0;

	if(s1[0]==s2[0])
		ans= 1+lcs2Helper(s1+1,s2+1,m-1,n-1,dp);
	else
	{
		int op1=lcs2Helper(s1,s2+1,m,n-1,dp);
		int op2=lcs2Helper(s1+1,s2,m-1,n,dp);
		ans= max(op1,op2);
	}

	return dp[m][n]=ans;
}

int lcs2(char*s1,char*s2)
{
	int m=strlen(s1);
	int n=strlen(s2);
	int **dp=new int*[m+1];
	for(int i=0; i<=m; i++)
	{
		dp[i]=new int [n+1];
		for(int j=0; j<=n; j++)
		{
			dp[i][j]=-1;
		}
	}

	int ans=lcs2Helper(s1,s2,m,n,dp);
	for(int i=0; i<=m; i++)
	{
		delete[]dp[i];
	}

	delete []dp;
	return ans;
}

//Using DP-Top Down Approach
int lcs3(char*s1,char*s2)
{
	int m=strlen(s1);
	int n=strlen(s2);
	int **dp=new int*[m+1];
	for(int i=0; i<=m; i++)
	{
		dp[i]=new int [n+1];
	}

	//Filling 0th row
	for(int j=0; j<=n; j++)
	{
		dp[0][j]=0;
	}

	//Filling 0th col
	for(int i=0; i<=m; i++)
	{
		dp[i][0]=0;
	}

	//Filling up the rest of the table
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(s1[m-i]==s2[n-j])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}

	int ans=dp[m][n];
	for(int i=0; i<=m; i++)
	{
		delete[]dp[i];
	}

	delete []dp;
	return ans;
}

//Printing lcs
void PrintLCS( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 

   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
  
   
   int index = L[m][n]; 
  
   
   char lcs[index+1]; 
   lcs[index] = '\0'; 
  
  
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; 
          i--; j--; index--;     
      } 
  
      
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   cout<<lcs<<endl; 
}

void solve()
{
	char a[100],b[100];
	cin>>a;
	cin>>b;
	int m=strlen(a);
	int n=strlen(b);

	cout<<lcs3(a,b)<<endl;
	PrintLCS(a,b,m,n);	
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