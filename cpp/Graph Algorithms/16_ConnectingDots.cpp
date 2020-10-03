#include<bits/stdc++.h>
using namespace std;
#define MAXN  1000

bool visited[51][51];
bool findCycle = false;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int fromX, int fromY, char needColor,int n, int m,char board[][MAXN])
{
	if(x < 0 || x >= n || y < 0 || y >= m) return;
	if(board[x][y] != needColor) return;
	if(visited[x][y])
	{
		findCycle = true;
		return;
	}
	visited[x][y] = true;
	for(int f = 0; f < 4; f++)
	{
		int nextX = x + dx[f];
		int nextY = y + dy[f];
		if(nextX == fromX && nextY == fromY) continue;
		dfs(nextX, nextY, x, y, needColor,n,m,board);
	}
}

int solve(char board[][MAXN],int n, int m)
{
    memset(visited, false, sizeof(visited));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!visited[i][j])
				dfs(i, j, -1, -1, board[i][j],n,m,board);
	
   if(findCycle)
       return 1;
    else
        return 0;
	
}

void solve()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
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