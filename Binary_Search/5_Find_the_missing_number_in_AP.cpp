#include<bits/stdc++.h>
using namespace std;

bool predicate(int arr[], int mid, int d){
	if(arr[0]+mid*d == arr[mid])
		return true;
	else
		return false;
}

int getMissingAP(int arr[], int n){
	int d = (arr[n-1]-arr[0])/n;
	int mid,ans;
	int low = 0;
	int high = n-1;
	while(low<=high){
		mid = (low+high)/2;
		if(predicate(arr,mid,d))
			low = mid+1;
		else{
			ans = mid;
			high = mid-1;
		}
	}
	return (arr[0] + ans*d);
	
}

int main(){
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	cout<<getMissingAP(arr,n)<<endl;	
}
