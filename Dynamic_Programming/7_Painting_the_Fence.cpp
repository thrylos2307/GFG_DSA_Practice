#include <iostream>                                                                                            
using namespace std;
#define mod 1000000007

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k,i;
		scanf("%d %d",&n,&k);
		long int memo[n+1] = {0};
		memo[0] = 0;
		memo[1] = k;
		memo[2] = k*k;
		for(i=3;i<=n;i++){
			memo[i] = ((k-1)*(( memo[i-1]%mod + memo[i-2]%mod )%mod))%mod;
		}
		
		cout<<memo[n]<<endl;
	}
	return 0;
}
