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
	ll n,d;
	cin>>n>>d;
    
    vector<tuple<ll,ll,ll>>v;
	f(i,0,n)
	{
		ll t,x,y;
		cin>>t>>x>>y;
		v.PB(make_tuple(t,x,y));
	}

	sort(all(v));

	ll tim[100000],speed[100000],cost[100000];
    tim[0]=get<0>(v[0]);
    cost[0]=get<1>(v[0]);
    speed[0]=get<2>(v[0]);
    ll index=0;
    ll z=v.size();
    for(ll i=1;i<z;i++)
    {
        if((get<0>(v[i]))!=(get<0>(v[i-1])))
        {
            index++;
            tim[index]=get<0>(v[i]);
            cost[index]=get<1>(v[i]);
            speed[index]=get<2>(v[i]);
            continue;
        }
        
        if((get<2>(v[i]) > speed[index]))
        {
            
            speed[index]=get<2>(v[i]);
            cost[index]=get<1>(v[i]);
        }
    
    }

    /*f(i,0,index+1)
    {
    	cout<<tim[i]<<" "<<cost[i]<<" "<<wrk[i]<<endl;
    }*/

    ll ans=cost[0];
    ll best_speed=speed[0];
    d=d-(speed[0]*(tim[1]-tim[0]));

    f(i,1,index+1)
    {
    	if(d<=0)
    		break;

    	else
    	{
    		if(speed[i]>best_speed)
    		{
    			best_speed=speed[i];
    			ans+=cost[i];
    			d=d-(speed[i]*(tim[i+1]-tim[i]));
    		}
    		else
    		{
    			d=d-(best_speed*(tim[i+1]-tim[i]));
    		}
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
	//cin>>t;
	while(t--)
	{
		solve();
	}
    return 0;
}