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
#define Maxi(a,b,c,d,e)                max(a,max(b,max(c,max(d,e))))

const ll MOD     = 1000000007;
const ll SIZE    = 100000;
const int INF    = 0x3f3f3f3f;
const ll ll_INF  = 0x3f3f3f3f3f3f3f3f;
const ld PI      = acos(-1);
const ll MAXN    = numeric_limits<ll>::max();
const ll MAX     = 2000000;

struct node
{
    int maxSum;
    int sum;
    int BPS;
    int BSS;

    node() 
    { 
        BPS= BSS = maxSum = -INF; 
        sum = -INF; 
    } 
    
};

void buildTree(int*arr, node*tree, int start, int end, int treeNode)
{

    if(start==end)
    {
        tree[treeNode].maxSum=arr[start];
        tree[treeNode].sum=arr[start];
        tree[treeNode].BPS=arr[start];
        tree[treeNode].BSS=arr[start];
        return;
    }

    int mid=(start+end)/2;

    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    node left=tree[2*treeNode];
    node right=tree[2*treeNode+1];

    tree[treeNode].sum=left.sum+right.sum;
    tree[treeNode].BPS=max(left.BPS,left.sum+right.BPS);
    tree[treeNode].BSS=max(right.BSS,right.sum+left.BSS);
    tree[treeNode].maxSum=Maxi(left.maxSum,right.maxSum,left.sum+right.BPS,right.sum+left.BSS,left.BSS+right.BPS);
    return;


}

node query(node*tree,int start, int end, int treeNode, int left, int right)
{
    //Completely outside given range
    if(start>right||end<left)
    {
        node nullNode;
        return nullNode;
    }

    //Completely inside given range
    if(start>=left&&end<=right)
        return tree[treeNode];

    //Partially inside and partially outside
    int mid=(start+end)/2;

    node left1=query(tree,start,mid,2*treeNode,left,right); //Going Left
    node right1=query(tree,mid+1,end,2*treeNode+1,left,right);//Going right
    
    node res;
    res.sum=left1.sum+right1.sum;
    res.BPS=max(left1.BPS,left1.sum+right1.BPS);
    res.BSS=max(right1.BSS,right1.sum+left1.BSS);
    res.maxSum=Maxi(left1.maxSum,right1.maxSum,left1.sum+right1.BPS,right1.sum+left1.BSS,left1.BSS+right1.BPS);

    return res;
    
}

void solve()
{
    int n;
    cin>>n;

    int arr[n];
    f(i,0,n)cin>>arr[i];

    node*tree=new node[4*n];

    buildTree(arr,tree,0,n-1,1);

    int q;
    cin>>q;

    while(q--)
    {
        int left,right;
        cin>>left>>right;
        node ans=query(tree,0,n-1,1,left-1,right-1);
        cout<<ans.maxSum<<endl;
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