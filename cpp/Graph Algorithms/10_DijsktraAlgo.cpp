// Author: rishab_1128

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

int getMinVertex(int*dist,bool*visited,int n)
{
	int minVertex=-1;
	for(int i=0; i<n; i++)
	{
		if(!visited[i]&&(minVertex==-1||dist[i]<dist[minVertex]))
			minVertex=i;
	}
	return minVertex;
}

void dijsktra(int**edges,int n)
{
	bool*visited=new bool[n]();
	int* dist=new int[n];

	for(int i=0; i<n; i++)
	{
		dist[i]=INT_MAX;
	}
	dist[0]=0;

	for(int i=0; i<n-1; i++)
	{
		//Get minVertex i.e. unvisited vertex with min distance
		int minVertex=getMinVertex(dist,visited,n);
		visited[minVertex]=true;

		//Explore all the neighbors of min vertex and update the dist array is reqd.
        for(int j=0; j<n; j++)
        {
        	if(edges[minVertex][j]!=0 && !visited[j])
        	{
        		if(dist[j]>dist[minVertex]+edges[minVertex][j])
        		{
        			dist[j]=dist[minVertex]+edges[minVertex][j];
        		}
        	}
        }

	}

	for(int i=0; i<n; i++)
	{
		cout<<i<<" "<<dist[i]<<endl;
	}

	delete[]visited;
	delete[]dist;


}

void solve()
{
	int n,e;
	cin>>n>>e;

	int**edges=new int*[n];
	for(int i=0; i<n; i++)
	{
		edges[i]=new int[n];
	}

	for(int i=0; i<e; i++)
	{
		int f,s,w;
		cin>>f>>s>>w;
		edges[f][s]=w;
		edges[s][f]=w;
	}
	
	dijsktra(edges,n);

	//Delete Edges
	for(int i=0; i<n; i++)
	{
		delete[]edges[i];
	}
	delete[]edges;
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