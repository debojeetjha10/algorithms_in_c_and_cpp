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

bool check(int **input,int n,int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(input[i][j]>=0)
				return true;
		}
	}

	return false;
}

int Kadane(int *arr, int n)
{
	int curr_ending_here=0;
	int best_so_far=0;

	for(int i=0; i<n; i++)
	{
		curr_ending_here+=arr[i];
		if(curr_ending_here<0)
			curr_ending_here=0;
		if(curr_ending_here>best_so_far)
			best_so_far=curr_ending_here;
	}

	return best_so_far;
}

int MaxSumRectangle(int **input, int n, int m)
{
	int best=0,l=0;
	while(l<m)
	{
		int r=l,best1=0;
		int arr[n];
		memset(arr,0,sizeof(arr));

		while(r<m)
		{
			for(int i=0; i<n; i++)
		    { 
			   arr[i]+=input[i][r];
		    }

		    int ans1=Kadane(arr,n);

		    //f(i,0,n)cout<<arr[i]<<" ";cout<<" ";cout<<ans1<<endl;

		    if(best1<ans1)
		    	best1=ans1;

		    r++;
		}

		if(best<best1)
			best=best1;

		l++;
	}

	return best;
}

void solve()
{
	int n,m;
	cin>>n>>m;

	int **input=new int*[n];
	for(int i=0; i<n; i++)
	{
		input[i]=new int [m];
		for(int j=0; j<m; j++)
			cin>>input[i][j];
	}

	if(check(input,n,m))
	{
		int ans=MaxSumRectangle(input,n,m);
	    cout<<ans<<endl;
	}

	else
	{
		int maxi=INT_MIN;
		f(i,0,n)
		{
			f(j,0,m)
			{
				maxi=max(maxi,input[i][j]);
			}
		}

		cout<<maxi<<endl;
	}

	
	for(int i=0; i<n; i++)
	{
		delete []input[i];
	}

	delete []input;	
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