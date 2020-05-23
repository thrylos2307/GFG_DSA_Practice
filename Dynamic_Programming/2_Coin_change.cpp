#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int n,amount,i,j;
	    scanf("%d",&n);
	    int* arr = new int[n];
	    for(i=0;i<n;i++)
	        scanf("%d",&arr[i]);
	    
	    scanf("%d",&amount);
	     int** memo = new int*[n+1];
	     for(i=0;i<=n;i++)
	        memo[i] = new int[amount+1];
	     
	     for(i=0;i<=amount;i++)
	        memo[0][i] = 0;
	     for(i=0;i<=n;i++)
	        memo[i][0] = 1;
	  
	     for(i=1;i<=n;i++){
	         for(j=1;j<=amount;j++){
	       
	             if(j-arr[i-1] >=0)
	                memo[i][j] = memo[i-1][j] + memo[i][j - arr[i-1]];
	             else
	                memo[i][j] = memo[i-1][j];
	         }
	     }
	     
	     cout<<memo[n][amount]<<endl;
	        
	}
	return 0;
}
