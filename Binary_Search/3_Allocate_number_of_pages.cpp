#include<bits/stdc++.h>
using namespace std;

bool predicate(long long int mid,long long int pages[],long long int n,long long int m){
	long long int count = 1,i,sumPage=0,maxn=0;
	
	for(i=0;i<n;i++){
		if(sumPage+pages[i]>mid){
			sumPage = pages[i];
			count++;
			if(count>m)
				return false;
		}
		else{
			sumPage+=pages[i];
			if(maxn<sumPage)
				maxn = sumPage;
		}
	}
	
	if(count<=m){
				return true;
			}
	return false;
}

long long int minMaxPages(long long int pages[],long long int n,long long int m){
	long long int i,max=0,sum=0,mid=0,final;
	if(n<m)
		return -1;
	
	bool flag = false;
	for(i=0;i<n;i++){
		sum+=pages[i];
		if(pages[i]>max)
			max = pages[i];
	}
	long long int low = max;
	long long int high = sum;
	final = low;
	while(low<=high){
		mid = low + (high-low)/2;

		if(low==high)
			flag = true;

		if(predicate(mid,pages,n,m)){
			final = mid;
			high = mid;}		
		else
			low = mid+1;
		
		if(flag)
			return final;
			
	}
	return -1;
	
}

int main(){
	int T;
	cin>>T;
	while(T--){
		long long int n,m,i;
		cin>>n;
		long long int pages[n];
		for(i=0;i<n;i++)
			cin>>pages[i];
		cin>>m;
	
		cout<<minMaxPages(pages,n,m)<<endl;
	}
	return 0;
}

