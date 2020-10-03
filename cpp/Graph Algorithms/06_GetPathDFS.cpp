//  Author: rishab_1128

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
#define Maxi(a,b,c,d,e)                max(a,max(b,max(c,max(d,e))))

const ll MOD     = 1000000007;
const ll SIZE    = 100000;
const int INF    = 0x3f3f3f3f;
const ll ll_INF  = 0x3f3f3f3f3f3f3f3f;
const ld PI      = acos(-1);
const ll MAXN    = numeric_limits<ll>::max();
const ll MAX     = 2000000;

vector<int> getPath(int**edges, int n, int starting_vertex, int end_vertex, bool*visited,vi v)
{
	
	if(starting_vertex==end_vertex)
	{
		v.PB(starting_vertex);
		return v;
	}

	visited[starting_vertex]=true;
	for(int i=0; i<n; i++)
	{
		if(i==starting_vertex)
			continue;
		if(edges[starting_vertex][i]==1)
		{
			if(visited[i])
			{
				continue;
			}

			v=getPath(edges,n,i,end_vertex,visited,v);
			if(v.size()==0)
				continue;
			else
			{
				v.PB(starting_vertex);
				return v;
			}
		}
	}

	return v;


}

void solve()
{
	int n,e;
	cin>>n>>e;

	int**edges=new int*[n];
	for(int i=0; i<n; i++)
	{
		edges[i]=new int[n];
		for(int j=0; j<n; j++)
		{
			edges[i][j]=0;
		}
	}

	for(int i=0; i<e; i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}

	bool*visited=new bool[n];
	for(int i=0; i<n; i++)
	{
		visited[i]=false;
	}


	int starting_vertex,end_vertex;
	cin>>starting_vertex>>end_vertex;

	vi v;
	v=getPath(edges,n,starting_vertex,end_vertex,visited,v);
	for(auto x: v)
		cout<<x<<" ";

	//Delete Edges Memory
	for(int i=0; i<n; i++)
	{
		delete[]edges[i];
	}
	delete[]edges;
    
    //Delete visited memory
	delete[]visited;	

	

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