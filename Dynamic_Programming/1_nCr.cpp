#include <iostream>
using namespace std;

#define mod 1000000007
#define n 1000
#define r 800
int main() {
    
    int i,j;
    int **memo = new int*[n+1];
	    for(i=0;i<=n;i++)
	    	memo[i]=new int[r+1];
	    
	    for(i=0;i<=r;i++)
	    	memo[i][i] = 1;
	    for(i=0;i<=n;i++)
	    	memo[i][0] = 1;
 
	    for(i=1;i<=r;i++){
	    	for(j=i+1;j<=n;j++){
	    		memo[j][i] = ((memo[j-1][i-1])%mod + (memo[j-1][i])%mod) %mod;
			}
		}
		 
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,R;
	    scanf("%d %d",&N,&R);
	    if(R==0 || N==R){
	    	cout<<1<<endl;
	    	continue;}
	    	
		R = min(R,N-R);
		 
	    cout<<memo[N][R]<<endl;
	}
	return 0;
}
