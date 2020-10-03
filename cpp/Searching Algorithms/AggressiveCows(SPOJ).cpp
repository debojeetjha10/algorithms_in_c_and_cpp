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


bool sortinrev(const pair<ll,STR> &a,  
               const pair<ll,STR> &b) 
{ 
       return (a.first > b.first); 
}

bool sortbysec(const pair<int,int> &a, 
                   const pair<int,int> &b) 
{ 
       return (a.second<b.second); 
}

bool isprime(ll n) 
{ 
    
    if (n <= 1)  return false; 
  
    for (ll i=2; i*i<=n; i++) 
        if (n%i == 0) 
            return false; 
  
    return true; 
} 

vll prime;
ll a[MAX];

void SOE()
{
    
    memset(a,1,sizeof(a));

    for(ll i=2;i*i<=MAX;i++){
      if(a[i])
        for(ll j=i*i;j<=MAX;j+=i){
          a[j]=0;
        }
    }

    f(i,2,MAX)
      if(a[i])
        prime.PB(i);
}

mll powers;
vector<ll> PrimeFactors(ll n)
{
	vll v;
	if(n%2==0)
	{
		v.PB(2);
	}

	while(n%2==0)
	{
		n=n/2;
		powers[2]++;
	}

	for(ll i=3; i<=sqrt(n); i++)
	{
		if(n%i==0)
			v.PB(i);
		while(n%i==0)
		{
			n=n/i;
			powers[i]++;
		}
	}

	if(n>2)
	{
		v.PB(n);
		powers[n]++;
	}

	return v;
}


ll FastModExpo(ll x, ll y, ll m)
{
	// To calc. (x^y)%m
	ll res=1;
	while(y>0)
	{
		if(y&1)
		{
			res=(res*x)%m;
		}
		x=(x*x)%m;
		y=y>>1;
	}

	return res;
}


ll diffbits(ll x,ll y)
{
	// To count how many bits of x are different from y//
	//Concept used in 467B//
	ll a=x^y;
	ll ans=setbits(a);
	return ans;
}

 
ll vis[100001];
vll adj[100001];  
void dfs(ll u)
{
 
  vis[u]=1;
  for(auto x: adj[u])
  {
 	if(vis[x]==0)
		dfs(x);
  }
 
}

long long Largest_Sum_Subarray(ll arr[], ll n)
{
	ll curr_ending_here=0;
	ll best_so_far=0;
	ll mx=-10000000;

	for(long long i=0; i<n; i++)
	{
		curr_ending_here+=arr[i];
		if(curr_ending_here<0)
			curr_ending_here=0;
		if(curr_ending_here>best_so_far)
			best_so_far=curr_ending_here;
		mx=max(mx,arr[i]);
	}

	if(mx<0)
		return mx;
	else
		return best_so_far;	
}

void solve()
{
	ll n,c;
	cin>>n>>c;

	ll a[n];
	f(i,0,n)cin>>a[i];

	sort(a,a+n);

	ll ans=0,L=0,R=a[n-1]-a[0],mid=L+(R-L)/2;
	while(L<=R)
	{
		ll pos=0,ct=1;
		f(i,pos+1,n)
		{
			if(a[i]-a[pos]>=mid)
			{
				ct++;
				pos=i;
			}
		}

		if(ct>=c)
		{
			ans=max(ans,mid);
			L=mid+1;
			mid=L+(R-L)/2;
		}
		else
		{
			R=mid-1;
			mid=L+(R-L)/2;
		}		

	}

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