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
typedef map<ll,ll>                     mll;//Author: rishab_1128

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

//ALL THESE FUNCTIONS WILL NOT WORK FOR NUMBERS WITH 0 IN IT
//Recursive Approach
long long alpha_code1(ll *n, ll size)
{
	if(size==1||size==0)
		return 1;
    
    long long output=alpha_code1(n,size-1);

    int num=n[size-2]*10+n[size-1];

    if(num<=26)
    {
    	output+=alpha_code1(n,size-2);
    }

    return output;	 
}

//Dynamic Approach 1(Recursive)
long long alpha_code2(ll *n, ll size, ll *arr)
{
	if(size==1||size==0)
		return 1;

	if(arr[size]>0)
		return arr[size];
    
    long long output=alpha_code2(n,size-1,arr);

    int num=n[size-2]*10+n[size-1];

    if(num<=26)
    {
    	output+=alpha_code2(n,size-2,arr);
    }

    arr[size]=output;

    return output;	 
}

//Dyanmic Approach 2(Iterative)
long long alpha_code3(ll *input, ll size)
{
	ll output[size+1];
	output[0]=1;
	output[1]=1;
	for(ll i=2; i<=size; i++)
	{
		output[i]=output[i-1];
		if(input[i-2]*10+input[i-1]<=26)
			output[i]+=output[i-2];
	}

	return output[size];
}

//THIS FUNC WILL ALSO WORK FOR NUMBER WITH 0 IN IT
long long alpha_code4(ll *n, ll size, ll *arr)
{
    int m=1e9+7;
    
	if(size==1||size==0)
		return 1;

	if(arr[size]>0)
		return arr[size];
    
    ll output=0;
    
    if(n[size-1]>0)
    	output=alpha_code4(n,size-1,arr);
    
    if(n[size-2]*10+n[size-1]>=10 && n[size-2]*10+n[size-1]<=26)
    {
            output=(output+alpha_code4(n,size-2,arr))%m;
    }
        
    
   arr[size]=output;
   return output;
    
}
void solve()
{
	while(1)
	{
            STR s;
	    cin>>s;

	    ll n=s.size();
	    ll num[n];
	    f(i,0,n)
	    {
	    	num[i]=s[i]-'0';
	    }

	    ll arr[n+1];
	    memset(arr,0,sizeof(arr));

	    if(s=="0")
	    	break;
   
	    ll ans=alpha_code4(num,n,arr);
	    cout<<ans<<endl;

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
