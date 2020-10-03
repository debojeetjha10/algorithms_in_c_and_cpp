#include<bits/stdc++.h>
using namespace std;
#define NMAX  55

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

int cc(int i, int j, int n, int**grid, bool**seen)
{
    if(i < 0 || j < 0) return 0;
    if(i == n || j == n) return 0;
    if(seen[i][j]) return 0;
    if(!grid[i][j]) return 0;
    
    seen[i][j] = true;
    int ans = 1;
    
    for(int k = 0 ; k < 4 ;k++){
            ans += cc( i + dx[k], j + dy[k], n, grid,seen);
        }
    
    return ans;
}

int solve(int n,char cake[NMAX][NMAX])
{
    int**grid=new int*[n];
    for(int i=0; i<n; i++)
    {
        grid[i]=new int[n];
        for(int j=0; j<n; j++)
        {
            if(cake[i][j]=='1')
                grid[i][j]=1;
            else
                grid[i][j]=0;
        }
    }

    bool**seen=new bool*[n];
    for(int i=0; i<n; i++)
    {
    	seen[i]=new bool[n];
    	for(int j=0; j<n; j++)
    	{
    		seen[i][j]=false;
    	}
    }
       
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            ans = max(ans, cc(i, j, n, grid,seen));
        }
    }
    
    //Delete grid
   for(int i=0; i<n; i++)
   {
   	   delete[]grid[i];
   }
   delete[]grid;

   //Delete seen
   for(int i=0; i<n; i++)
   {
   	   delete[]seen[i];
   }
   delete[]seen;
	
    
   return ans;

   
}

char cake[NMAX][NMAX];
int main()
{
	std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}