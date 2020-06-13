#include<bits/stdc++.h>
using namespace std;

bool predicate(int time[], int cooks, int mid, int prata){
	int nextAvailable[cooks] = {0};
	int currRound[cooks] = {0};
	int cooked =0;
	int i,j;
	bool flag = false;
	for(i=0;i<mid;){
		int next = mid-1;
		for(j=0;j<cooks;j++){
			if(nextAvailable[j]<=i)
			{
				if(i>0)
					cooked++;
				nextAvailable[j] = time[j]*( pow((currRound[j]+1),2) + (currRound[j]+1) )/2;
			
				currRound[j]++;	
				
			}
				next = min(next,nextAvailable[j]);
		}

		if(flag)
			break;
		if(next==mid-1)
			flag = true;
		
		i = next;
	}
	for(i=0;i<cooks;i++){
	
		if(nextAvailable[i]==mid){
		
			cooked++;
		}
	}		
	if(cooked>=prata)
		return true;
	else
		return false;	
}

int bestTime(int time[], int cooks, int prata, int maxTime){
	int low =0,mid,ans = 0;
	int high = maxTime*(prata*prata + prata)/2; //nth term of Quadratic Sequence is k(n^2 + n)/2 where k is the rank of the cook

	bool flag = false;
	while(high>=low){
		mid = (high+low)/2;
		
		if(low==high)
			flag = true;
		if(mid==0)
			break;

		if(predicate(time, cooks, mid,prata)){
			ans = mid;
			high = mid;
		}
		else
			low = mid+1;
		
		if(flag)
			break;
	}
	return ans;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int prata,cooks,i,maxTime=0;
		cin>>prata>>cooks;
		
		int time[cooks];
		
		for(i=0;i<cooks;i++){
			scanf("%d",&time[i]);
			maxTime = max(maxTime,time[i]);
	}
		cout<<bestTime(time,cooks,prata,maxTime)<<endl;
	}
}
