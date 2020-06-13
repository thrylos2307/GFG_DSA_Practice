#include <bits/stdc++.h>
using namespace std;

int bsearch(int second[], int val,int low,int high){
	int mid;
	
	while(high>=low){
			mid = (high+low)/2;
			if(second[mid]==val)
				return mid;
			
			else if(second[mid]>val)
				high = mid -1;
			else
				low = mid+1;			
	}
	return -1;
}

int largeSum(int first[], int second[],long long int pfirst[], long long int psecond[], int f, int s){
	int i;
	long long int sum = 0;
	int pref = -1,pres = -1;
	for(i=0;i<f;i++){
		int search = first[i];
		
		int indx = bsearch(second,search,0,s-1);
		if(indx!=-1){
		
		if(pref==-1&&pres==-1)
			sum+=max(pfirst[i] , psecond[indx]);
		
		else
		sum+= max( pfirst[i]-pfirst[pref] , psecond[indx] - psecond[pres] );
		
		pref = i;
		pres = indx;
		
		}
	}
	if(pref==-1&&pres==-1)
	 sum = max(pfirst[f-1] , psecond[s-1]);
	else
	sum+= max( pfirst[f-1]-pfirst[pref] , psecond[s-1] - psecond[pres] );
		
	return sum;
	
}

int main(){
	int f,s;
	do{
		int i,temp;
		
		cin>>f;
		if(f==0)
			break;
		int first[f];
		long long int prefirst[f];
		cin>>first[0];
		prefirst[0] = first[0];
		for(i=1;i<f;i++){
			cin>>temp;
			first[i] = temp;
			prefirst[i] = prefirst[i-1] + temp;
		}
		
		cin>>s;
		int second[s];
		long long int presecond[s];
		cin>>second[0];
		presecond[0] = second[0];
		
		for(i=1;i<s;i++){
			cin>>temp;
			second[i] = temp;
			presecond[i] = presecond[i-1] + temp;
		}
		
		cout<<largeSum(first,second,prefirst,presecond,f,s)<<endl;
		
	}while(f!=0);
	return 0;
}


