//Author: rishab_1128

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}

	sort(arr,arr+n,greater<int>());

	for(int i=0; i<n-2; i++)
	{
		if(arr[i+1]+arr[i+2]<=arr[i])
			continue;
		cout<<arr[i+2]<<" "<<arr[i+1]<<" "<<arr[i]<<endl;
		return;
	}

	cout<<-1<<endl;
	return;

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