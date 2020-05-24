#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int size,i,j, xyz[3];
		scanf("%d",&size);
		cin>>xyz[0]; cin>>xyz[1]; cin>>xyz[2];
		
		int memo[4][size+1];
		for(i=0;i<=size;i++)
			memo[0][i] = 0;
		
		for(i=1;i<=3;i++){
			for(j=1;j<=size;j++){
				if(j-xyz[i-1]<0){
					memo[i][j] = memo[i-1][j];
				}
				else if(j == xyz[i-1])
					memo[i][j] = max(1 , memo[i-1][j]);
				else if( j > xyz[i-1])
				{
					if(memo[i][j-xyz[i-1]] == 0)
					{
						memo[i][j] = memo[i-1][j];						
					 } 
					 else{
					 	memo[i][j] = max(1+memo[i][j-xyz[i-1]] , memo[i-1][j]);
					 }
				}				
			}
		}
		cout<<memo[3][size]<<endl;
	}
	return 0;
}
