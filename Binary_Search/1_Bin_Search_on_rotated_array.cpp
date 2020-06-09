#include <bits/stdc++.h> 
using namespace std;

int sanitize(int mid,int mod,int num){
	if(mid>=mod)
		return (mid-mod);
	else
		return (mid+num-mod);
}

int binarySearch(int arr[],int l,int h,int val,int mod,int num){
	if(h>=l){
		int mid = l + (h-l)/2;
		
		int actualMid = sanitize(mid,mod,num);
		
		if(arr[actualMid]==val)
			return actualMid;
		
		if(arr[actualMid]>val)
			return binarySearch(arr,l,mid-1,val,mod,num);
		
		return binarySearch(arr,mid+1,h,val,mod,num);
	}
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int num,find,i;
		scanf("%d",&num);
		int arr[num];
		int prev = -1,temp=0,pivot=-1;
		for(i=0;i<num;i++){
			scanf("%d",&temp);
			arr[i] = temp;
			if(temp<prev){
				pivot = i;
			}
			prev = temp;
		}
		
		if(pivot==-1){
		    pivot = num;}
		scanf("%d",&find);
		
		cout<<binarySearch(arr,0,num-1,find,num-pivot,num)<<endl;
	}
	
	return 0;
}
