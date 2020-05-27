#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int n,i,j;
		scanf("%d",&n);
		int arr[n] , memo[n] = {1},max=1;
		for(i=0;i<n;i++){
			cin>>arr[i];
			memo[i] = 1;}
			
		
		memo[0] = 1;
		for(i=1;i<n;i++){
			for(j=i-1;j>=0;j--){
				if(arr[j] < arr[i])
				{
					if(memo[j]+1 > memo[i]){
					
						memo[i] = memo[j] +1;
						if(memo[i] > max)
							max = memo[i];
					}
					
				}
			}
		}
			
	cout<<max<<endl;	
	}
	return 0;
}
