#include<bits/stdc++.h>
using namespace std;

bool predicate(int mid, int stalls[], int n, int c){
	int count = 1,i; //placing first cow at first stall
	int prev = stalls[0]; //stores the previous position where cow is placed
	for(i=1;i<n;i++){
		if(stalls[i] - prev >= mid)
		{
			count++;
			prev = stalls[i];
			if(count==c)
				return true;
		}
	}
	return false;
	
}

int setCows(int stalls[],int n, int c){
	sort(stalls,stalls+n);
	
	int low  = stalls[0];
	int high = stalls[n-1];
	int mid;
	
	while(high - low >1){
	
	 mid = low + (high-low)/2;
	
	if(predicate(mid,stalls,n,c))
		low = mid;
	else
		high = mid;
	}
	return low;
}

int main()
{
int T;
scanf("%d",&T);
while(T--){
	int n,c,i;
	cin>>n;
	cin>>c;
	int stalls[n];
	
	for(i=0;i<n;i++)
		cin>>stalls[i];
	
	cout<<setCows(stalls,n,c)<<endl;
}

} 
