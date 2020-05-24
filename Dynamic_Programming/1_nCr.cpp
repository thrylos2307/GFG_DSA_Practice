#include <iostream>
using namespace std;

#define mod 1000000007
#define n 500
#define r 400


int main() {
    
    int i,j;
    int **memo = new int*[n+1];
	    for(i=0;i<=n;i++)
	    	memo[i]=new int[r+1];
	    
	     for(i=0;i<=n;i++)
	    	memo[i][0] = 1;
	    for(i=1;i<=r;i++)
	    	memo[i][i] = 1;
	   
 
	    for(i=1;i<=r;i++){
	    	for(j=i+1;j<=n;j++){
	    
	    		memo[j][i] = ((memo[j-1][i-1]) + (memo[j-1][i]));
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
	  
	    cout<<memo[N][R]<<endl;
	}
	return 0;
}
