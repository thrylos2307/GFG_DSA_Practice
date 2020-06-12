#include<bits/stdc++.h>
using namespace std;

bool predicate(int mid, int num){
	int count =0;
	for(int i=5;i<=mid;i*=5){
		count+= mid/i;
	}
	if(count>=num)
		return true;
	else 
		return false;
	
}

int smallestFact(int num){
	int low = 5;  //has 1 trailing 0
	int high = 410; //400 has 99 trailing zeros
	int mid,ans;
	while(low<=high){
		mid = (low+high)/2;
		
		if(predicate(mid,num)){
			ans = mid;
			high = mid-1;}
		else
			low = mid+1;	
		
		
	}
	return ans;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int num;
		cin>>num;
		
		cout<<smallestFact(num)<<endl;
	}
}
