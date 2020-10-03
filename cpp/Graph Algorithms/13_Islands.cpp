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


void ConComp(int**edges, int n, int starting_vertex, bool*visited)
{
	queue<int>q;
	q.push(starting_vertex);
	visited[starting_vertex]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=1; i<=n; i++)
		{
			if(i==x)
			{
				continue;
			}

			if(edges[x][i]==1&&visited[i]==false)
			{
				q.push(i);
				visited[i]=true;
			}
		}
	}
}

int BFS(int**edges,int n)
{
    int ct=0;
	bool*visited=new bool[n+1];
	for(int i=1; i<=n; i++)
	{
		visited[i]=false;
	}

	for(int i=1; i<=n; i++)
	{
		if(!visited[i])
		{
			ct++;
			ConComp(edges,n,i,visited);
		}
	}

	delete[]visited;
	return ct;	
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int**edges=new int*[n+1];
    
	for(int i=0; i<=n; i++)
	{
		edges[i]=new int[n+1];
		for(int j=0; j<=n; j++)
		{
			edges[i][j]=0;
		}
	}
    
	for(int i=0; i<m; i++)
    {
        edges[u[i]][v[i]]=1;
        edges[v[i]][u[i]]=1;
    }
    
    int ans=BFS(edges,n);
    
    //Delete Edges Memory
	for(int i=0; i<=n; i++)
	{
		delete[]edges[i];
	}
	delete[]edges;
    
    return ans;
    
}