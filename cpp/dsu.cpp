#include<bits/stdc++.h>
using namespace std;

const int SIZE= 100000+10;

int link[SIZE],size[SIZE];


//finding the leader element with path compression

int find(int x){
    if(x==link[x]) return x;
    else return link[x]=find(link[x]);
}


//Uniting the two diff elements

void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(size[a]>=size[b]){
    	link[b]=a;
    	size[a]+=size[b];
    }
    else{
    	link[a]=b;
    	size[b]+=size[a];
    }
    
}



int main(){

// n is the no of nodes/elements
// m is the no of edges


int n,m;
cin>>n>>m;

for(int i=1;i<n+1;i++) link[i]=i;

vector<pair<int,int>> vp;

for(int i=0;i<m;i++){
	cin>>vp[i].first>>vp[i].second;  //The related elements
}

for(int i=0;i<m;i++){
    int fir=vp[i].first;
    int sec=vp[i].second;

    if(find(fir)!=find(sec)){
        // fir and sec are related but are not on the same set
        // so we have to unite them.
        unite(fir,sec);
      
    }
}


 
return 0;
}
