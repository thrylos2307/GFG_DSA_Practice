#include<bits/stdc++.h>
using namespace std;

struct Job{
	int start;
	int finish;
	int weight;
};

bool compare(Job s1, Job s2){
	return (s1.finish<s2.finish);
}

int jobSearch(Job jobs[],int i){
	int low,high,mid,ans;
	bool found = false;
	low = 0;
	high = i;
	while(high>=low){
		mid = (high+low)/2;
		if(jobs[mid].finish<=jobs[i].start){
			ans = mid;
			found = true;
			low = mid+1;}
		else
			high = mid-1;		
	}
	
	if(found)
		return ans;
	else
		return -1;
	
}

int getMaxProfit(Job jobs[],int n){
	sort(jobs,jobs+n,compare);
	int i;
	int dp[n];
	dp[0] = jobs[0].weight;
	
	for(i=1;i<n;i++){
		int currWt = jobs[i].weight;
		int ind = jobSearch(jobs,i);
		
		if(ind!=-1){
			currWt+= dp[ind];
		}
		
		dp[i] = max(dp[i-1],currWt);
	}
//	cout<<endl;
//	for(i=0;i<n;i++)
//		cout<<dp[i]<<" ";
	
//	cout<<endl;
	return dp[n-1];
	
	
}

int main(){
	int n,i;
	cin>>n;
	Job jobs[n];
	for(i=0;i<n;i++){
		cin>>jobs[i].start;
		cin>>jobs[i].finish;
		cin>>jobs[i].weight;
	}
	cout<<getMaxProfit(jobs,n);
	
	return 0;
}
