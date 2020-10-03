#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
const int N=100005;
long long int lazy[4*N];
long long int seg[4*N];
 
void build(int low,int high,int node)
{
    if(low>high)
    return;
    if(low == high)
    {
        seg[node]=0;
        return;
    }
    int mid = (low+high)/2;
    build(low,mid,2*node);
    build(mid+1,high,2*node+1);
    seg[node]=seg[2*node]+seg[2*node+1];
}
 
void updateLazy(int low,int high,int lq,int hq,int node,long long int val)
{
    if(lazy[node])
    {
        seg[node]+=(high-low+1)*lazy[node];
        if(high!=low)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(low>hq || high<lq)
    return;
    if(lq<=low && high<=hq)
    {
        seg[node]+=(high-low+1)*val;
        if(high!=low)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    int mid=(low+high)/2;
    updateLazy(low,mid,lq,hq,2*node,val);
    updateLazy(mid+1,high,lq,hq,2*node+1,val);
    seg[node]=seg[2*node]+seg[2*node+1];
}
 
long long int query(int low,int high,int lq,int hq,int node)
{
    if(lazy[node])
    {
        seg[node]+=(high-low+1)*lazy[node];
        if(high!=low)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(low>hq || high<lq)
    return 0;
    if(lq<=low && high<=hq)
    {
        return seg[node];
    }
    int mid=(low+high)/2;
   return query(low,mid,lq,hq,2*node)+query(mid+1,high,lq,hq,2*node+1);
}
int main()
{
    std::ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    int n,q;
    while(t--)
    {
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
        scanf("%d %d",&n,&q);
        int type;
        int x,y;
        long long int val;
        build(0,n-1,1);
        while(q--)
        {
            scanf("%d",&type);
            //printf("%dhh\n",type);
            if(type)
            {
                scanf("%d %d",&x,&y);
                printf("%lld\n",query(0,n-1,x-1,y-1,1));
            }
            else
            {
                scanf("%d %d %lld",&x,&y,&val);
                updateLazy(0,n-1,x-1,y-1,1,val);
            }
        }
         
    }
     
    return 0;
     
}