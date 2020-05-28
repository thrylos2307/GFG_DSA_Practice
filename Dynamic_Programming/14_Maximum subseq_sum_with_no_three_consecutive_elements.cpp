#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,i;
	cin>>n;
	int arr[n],memo[n] = {0};
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	memo[0] = arr[0];
	memo[1] = arr[0]+arr[1];
	memo[2] = max( memo[1] , max( memo[0] +arr[2] , arr[2]+arr[1] ) );
	for(i=3;i<n;i++){
		memo[i] = max( memo[i-1] , max( memo[i-2] + arr[i] , memo[i-3] + arr[i-1] + arr[i] ) );
	}

	cout<<memo[n-1]<<endl;
	return 0;
}

