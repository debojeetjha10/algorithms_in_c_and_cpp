

#include<bits/stdc++.h>
using namespace std;




int main(){
	
// binary search algo to find an element in an sorted array;

int n;  //size of array
cin>>n;
 
int ar[n];
for(int i=0;i<n;i++) cin>>ar[i]; //Taking user input

sort(ar,ar+n); //bnary search can be applied on sorted array only

int target;  //element we have to find
cin>>target;

bool flag=false;

int l=0,r=n-1;
while(l<=r){
	int mid=(l+r)/2;
	if(ar[mid]==target){
		//we found the element
		
		flag=true;
		break;
	}
	else if(target>ar[mid]) {  // we have to move right
		l=mid+1;
	}
	else{  // we have to move left
		r=mid-1;
	}

}

if(flag==false){
	//The element is not present
}



	return 0;
}

