//Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;

	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	sort(a,a+n);

	int small=a[0]+k;
	int big=a[n-1]-k;

	if(small>big)
		swap(small,big);

	for(int i=1; i<n-1; i++)
	{
		int subt=a[i]-k;
		int add=a[i]+k;

		if(subt>=small or add<=big)
			continue;
		else if(subt<small and add>big)
		{
			if(big-subt<=add-small)
				small=subt;
			else
				big=add;
		}

	}

	cout<<big-small<<endl;

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