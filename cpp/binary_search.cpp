// i_m_arin

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef priority_queue<ll> pqll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef map<ll,ll> mpll;
typedef set<ll> stll;

#define f(i, a, n) 	for(ll i=a; i<(ll)n; i++)
#define f2(i, a, b) for(ll i=a; i<=(ll)b; i++)
#define pb 			push_back
#define ff 			first
#define ss 			second
#define pf			push_front
#define mp			make_pair
#define all(a)		(a).begin(),(a).end()
#define decimal(x)	fixed<<setprecision(x)
#define fsort(a)	sort(all(a))
#define rsort(a)	sort(all(a),greater<>())
#define fast_io		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem0(a)		memset(a,0,sizeof(a))
#define mem1(a)		memset(a,-1,sizeof(a))
#define lcm(a,b)	(a*b)/__gcd(a,b)
#define ub(v,x)		upper_bound(all(v),x)-v.begin()
#define lb(v,x)		lower_bound(all(v),x)-v.begin()

const ld PI  = acos(-1);
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const ll SIZE= 100000+5;

struct edge {
	int a,b,w;
};

edge ar[SIZE];
int link[SIZE];

bool comp(edge a,edge b){
	return a.w<b.w;
}


int find(int a){
	if(a==link[a]) return a;
	else return link[a]=find(link[a]);
}

void unite(int a,int b){
	a=find(a);
	b=find(b);
	link[b]=a;
}



int main(){
	
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
	cin>>ar[i].a>>ar[i].b>>ar[i].w;
}

sort(ar,ar+m,comp);

for(int i=0;i<n+1;i++) link[i]=i;

ll sum=0;

for(int i=0;i<m;i++){
	if(find(ar[i].a)!=find(ar[i].b)){
		unite(ar[i].a,ar[i].b);
		sum+=ar[i].w;
	}
}

cout<<sum<<"\n";


return 0;
}