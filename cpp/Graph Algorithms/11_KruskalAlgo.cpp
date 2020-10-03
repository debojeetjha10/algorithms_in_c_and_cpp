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

class Edge
{
public:
	int src;
	int dest;
	int weight;

};

bool compare(Edge e1, Edge e2)
{
	return e1.weight<e2.weight;
}

int getParent(int v,int*parent)
{
	if(parent[v]==v)
		return v;
	return getParent(parent[v],parent);
}

Edge* kruskals(Edge* edges, int n, int E)
{
	//Sorted the edges array in increasing order
	sort(edges,edges+E,compare);

	Edge*output=new Edge[n-1];
	int*parent=new int[n];
	for(int i=0; i<n; i++)
	{
		parent[i]=i;
	}

	int count=0,i=0;
	while(count<n-1)
	{
		//Check the topmost parent of v1 and v2 where v1 and v2 are the vertices of the current edge

		Edge currentEdge=edges[i];
		int srcParent=getParent(currentEdge.src,parent);
		int destParent=getParent(currentEdge.dest,parent);

		if(srcParent!=destParent)
		{
			output[count]=currentEdge;
			count+=1;
			parent[srcParent]=destParent;
		}
		i++;

	}

	return output;  

}


void solve()
{
	int n,E;
	cin>>n>>E;

	Edge* edges=new Edge[E];

	for(int i=0; i<E; i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		edges[i].src=s;
		edges[i].dest=d;
		edges[i].weight=w;
	}

	Edge* output=kruskals(edges,n,E);

	for(int i=0; i<n-1; i++)
	{
		if(output[i].src<output[i].dest)
		{
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else
		{
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
		}
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