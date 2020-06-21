#include <bits/stdc++.h>
using namespace std;

int minSteps(int arr[], int n){
	int dist[n];
	for(int i=0; i<n;i++)
		dist[i]= INT_MAX;

	dist[0] = 0;
	
	queue<int> q;
	q.push(0);
	
	while(!q.empty()){
		int curr = q.front();
		
		for(int i=curr+1; i <= arr[curr]+curr; i++){
			if( i<n ){
				dist[i] = min( dist[i] , dist[curr] +1 );
				q.push(i);
				if(i==n-1)
					return dist[i];
			}
			else 
				break;
		}
		q.pop();
	}
	return dist[n-1];
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n;i++)
			cin>>arr[i];
			
		int ans = minSteps(arr,n);

		if(ans == INT_MAX)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
