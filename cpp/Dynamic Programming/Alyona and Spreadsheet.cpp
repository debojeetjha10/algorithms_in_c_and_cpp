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

void solve()
{
	ll n,m;
	cin>>n>>m;

	ll a[n+1][m+1];
	f(i,1,n+1)
	{
		f(j,1,m+1)
		{
			cin>>a[i][j];
		}
	}

	ll dp[n+1][m+1];//dp[i][j]:= it stores that in jth column from which row till ith row is sorted
	f(j,1,m+1)
	{
		dp[1][j]=1;
	}

	f(i,2,n+1)
	{
		f(j,1,m+1)
		{
			if(a[i][j]>=a[i-1][j])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=i;

		}
	}

	/*f(i,1,n+1)
	{
		f(j,1,m+1)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
    
    ll row[n+1];
	f(i,1,n+1)
	{
		ll mn=ll_INF;
		f(j,1,m+1)
		{
			mn=min(mn,dp[i][j]);
			row[i]=mn;
		}
	}

	//f(i,1,n+1)cout<<row[i]<<" ";cout<<endl;

	w(t)
	{
		ll l,r;
		cin>>l>>r;

		if(l<row[r])
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}	

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