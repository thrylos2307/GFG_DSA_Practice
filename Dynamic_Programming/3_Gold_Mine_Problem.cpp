#include <iostream>
using namespace std;


int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,i,j;
        scanf("%d %d",&n,&m);
        int mine[n][m];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>mine[i][j];
            }
        }
        
        if(n==1)
        	{int sum = 0;
        		for(i=0;i<m;i++)
        		{
        			sum +=mine[0][i];
				}
				cout<<sum<<endl;
				continue;
			}
			
       int memo [n][m];
       for(i=0;i<n;i++)
        memo[i][0] = mine[i][0];
        
       for(j=1;j<m;j++){
           for(i=0;i<n;i++){
               if(i==0)
                   memo[i][j] = max(memo[0][j-1] , memo[1][j-1]) + mine[i][j];
               else if(i==(n-1))
                   memo[i][j] = max(memo[n-1][j-1] , memo[n-2][j-1]) + mine[i][j];
               else{
                   memo[i][j] = max(memo[i-1][j-1] , max(memo[i][j-1] , memo[i+1][j-1])) + mine[i][j];
               }
                 
           }
       }
  
       int max = 0;
       for(i=0;i<n;i++)
        {
            if(max < memo[i][m-1])
                max = memo[i][m-1];
        }
       
       cout<<max<<endl;
    }
	return 0;
}
