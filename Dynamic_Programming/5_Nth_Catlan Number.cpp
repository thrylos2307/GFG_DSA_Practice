#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using namespace std;
#define n 200
#define r 100

int main() {
    int i,j;
	mp::cpp_int memo[n+1][r+1];
	
	     for(i=0;i<=n;i++)
	    	memo[i][0] = 1;
	    for(i=1;i<=r;i++)
	    	memo[i][i] = 1;
	   
 
	    for(i=1;i<=r;i++){
	    	for(j=i+1;j<=n;j++){
	    
	    		memo[j][i] = ((memo[j-1][i-1] ) + (memo[j-1][i]));
			}
		}

		 
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	   
	 mp::cpp_int ans = memo[2*N][N] / (N+1);
	    cout<<ans<<endl;
	}
	return 0;
}