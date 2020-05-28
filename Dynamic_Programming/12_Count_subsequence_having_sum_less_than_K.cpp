#include<bits/stdc++.h>                                                                                            
using namespace std;

int main() {
	int n,k,i,j;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			dp[i][j] = dp[i-1][j];
			
			if(arr[i-1] <= j){
				dp[i][j] += dp[i-1][j/arr[i-1]] + 1; 
			}
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
