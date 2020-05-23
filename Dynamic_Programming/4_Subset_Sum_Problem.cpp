#include <iostream>
using namespace std;
int memo[100][100001];
bool check(int ind,int sum,int arr[],int size){
	if(memo[ind][sum]==1)
		return true;
	if(memo[ind][sum]==0)
		return false;

	if(ind == size)
			return false;
	if(sum-arr[ind]==0)
	    return true;
	    
	if(check(ind+1,sum-arr[ind],arr,size)){
			memo[ind][sum] = 1;
			return true;
		}
			
	
	else if(check(ind+1,sum,arr,size)){
		memo[ind][sum] = 1;
		return true;
	}
	 	
	else{
		memo[ind][size] = 0;
		return false;
	}
		
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--){
	int size,i,j,sum=0;
	scanf("%d",&size);
	int* arr = new int[size];
	
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	if(sum%2 == 1)
	{
		cout<<"NO"<<endl;
		continue;
	}
	else{
		sum = sum/2;

		for(i=0;i<size;i++){
			for(j=0;j<=sum;j++)
				memo[i][j]=-1;
		}
		
		for(i=0;i<size;i++)
			memo[i][0] = 1;
		
		if(check(0,sum,arr,size))	
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		}
	
	}

	return 0;
}
