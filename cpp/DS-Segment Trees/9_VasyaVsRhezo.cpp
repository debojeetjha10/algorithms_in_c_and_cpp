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

void buildTree(int*A, int*B, int*tree, int start, int end, int treeNode)
{

    if(start==end)
    {
        tree[treeNode]=start;
        return;
    }

    int mid=(start+end)/2;

    buildTree(A,B,tree,start,mid,2*treeNode);
    buildTree(A,B,tree,mid+1,end,2*treeNode+1);

    int x1=tree[2*treeNode];
    int x2=tree[2*treeNode+1];

    if(A[x1]>A[x2])
        tree[treeNode]=x1;
    else if(A[x2]>A[x1])
        tree[treeNode]=x2;
    else
    {
        if(B[x1]>B[x2])
            tree[treeNode]=x2;
        else
            tree[treeNode]=x1;
    }

    return;
}

/*void updateTree(int*arr, int*tree, int start, int end, int treeNode, int index, int value)
{
    if(start==end)
    {
        tree[treeNode]=value;
        arr[index]=value;
        return;
    }

    int mid=(start+end)/2;
    if(index>mid)
    {
        updateTree(arr,tree,mid+1,end,2*treeNode+1,index,value);
    }
    else
    {
        updateTree(arr,tree,start,mid,2*treeNode,index,value);
    }

    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}*/

int query(int*A, int*B, int*tree,int start, int end, int treeNode, int left, int right)
{
    //Completely outside given range
    if(start>right||end<left)
        return 0;

    //Completely inside given range
    if(start>=left&&end<=right)
        return tree[treeNode];

    //Partially inside and partially outside
    int mid=(start+end)/2;

    int ans1=query(A,B,tree,start,mid,2*treeNode,left,right); //Going Left
    int ans2=query(A,B,tree,mid+1,end,2*treeNode+1,left,right);//Going right

    if(A[ans1]>A[ans2])
        return ans1;
    else if(A[ans2]>A[ans1])
        return ans2;
    else
    {
        if(B[ans1]>B[ans2])
            return ans2;
        else
            return ans1;
    }
}

void solve()
{
    int n;
    cin>>n;

    int*A=new int[n+1];
    int*B=new int[n+1];

    int*tree=new int[4*n];

    f(i,1,n+1)cin>>A[i];
    f(i,1,n+1)cin>>B[i];

    buildTree(A,B,tree,1,n,1);

    /*for(int i=1; i<=15; i++)
        cout<<tree[i]<<endl;**/ //Tree is perfect

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int ans=query(A,B,tree,1,n,1,l,r);
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