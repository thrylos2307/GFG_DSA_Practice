#include <iostream>                                                                                            
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int len1, len2,i=0,j=0,k=0,match=-1,count=-1;
		scanf("%d %d",&len1,&len2);
		string str1, str2;
		getline(cin,str1);
		getline(cin,str1);
		getline(cin,str2);
		
		int dp[len2+1][len1+1] = {0};
		
		for(i=0;i<=len2;i++)
			dp[i][0] = 0;
		
		for(i=0;i<=len1;i++)
			dp[0][i] = 0;
		
		for(i=1;i<=len2;i++){
			for(j=1;j<=len1;j++){
				if(str2[i-1] == str1[j-1])
					dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
			
				}
			}
			cout<<dp[len2][len1]<<endl;
		}
			

	return 0;
}
