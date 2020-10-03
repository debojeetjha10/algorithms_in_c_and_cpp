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

struct node
{
    int even;
    int odd;
};

void buildTree(int*arr, node*tree, int start, int end, int treeNode)
{

    if(start==end)
    {
       if(arr[start]%2==0)
       {
            tree[treeNode].even=1;
            tree[treeNode].odd=0;
       }
       else
       {
            tree[treeNode].even=0;
            tree[treeNode].odd=1;
       }
       return;
    }

    int mid=(start+end)/2;

    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode].even=tree[2*treeNode].even+tree[2*treeNode+1].even;
    tree[treeNode].odd=tree[2*treeNode].odd+tree[2*treeNode+1].odd;
    return;
}

void updateTree(int*arr, node*tree, int start, int end, int treeNode, int index, int value)
{
    if(start==end)
    {
       if(arr[index]%2==0&&value%2!=0)
       {
            tree[treeNode].even--;
            tree[treeNode].odd++;
            arr[index]=value;
       }
       else if(arr[index]%2!=0&&value%2==0)
       {
            tree[treeNode].even++;
            tree[treeNode].odd--;
            arr[index]=value;
       }
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

    tree[treeNode].even=tree[2*treeNode].even+tree[2*treeNode+1].even;
    tree[treeNode].odd=tree[2*treeNode].odd+tree[2*treeNode+1].odd;
    return;
}

pair<int,int> query(node*tree,int start, int end, int treeNode, int left, int right)
{
    //Completely outside given range
    if(start>right||end<left)
        return {0,0};

    //Completely inside given range
    if(start>=left&&end<=right)
        return {tree[treeNode].even,tree[treeNode].odd};

    //Partially inside and partially outside
    int mid=(start+end)/2;

    pii ans1=query(tree,start,mid,2*treeNode,left,right); //Going Left
    pii ans2=query(tree,mid+1,end,2*treeNode+1,left,right);//Going right

    return {ans1.FF+ans2.FF,ans1.SS+ans2.SS};
}

void solve()
{
    int n;
    cin>>n;

    int*arr=new int[n];
    f(i,0,n)cin>>arr[i];

    node*tree=new node[4*n];

    buildTree(arr,tree,0,n-1,1);

    int q;
    cin>>q;
    while(q--)
    {
        int var,x,y;
        cin>>var>>x>>y;
        if(var==0)
        {
            updateTree(arr,tree,0,n-1,1,x-1,y);
        }
        else if(var==1)
        {
            pii ans=query(tree,0,n-1,1,x-1,y-1);
            cout<<ans.FF<<endl;
        }
        else
        {
            pii ans=query(tree,0,n-1,1,x-1,y-1);
            cout<<ans.SS<<endl;
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