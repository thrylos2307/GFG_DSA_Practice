#include<bits/stdc++.h>                                                                                            
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int len1, len2,len3,i=0,j=0,k=0;
		
		scanf("%d %d %d",&len1,&len2,&len3);
		string str1, str2,str3;
		cin>>str1;
		cin>>str2;
		cin>>str3;
		
	    int dp[len2+1][len1+1][len3+1];
		memset(dp, 0, sizeof(dp));
		
		for(i=0;i<=len2;i++)
			dp[i][0][0] = 0;
		
		for(i=0;i<=len1;i++)
			dp[0][i][0] = 0;
		
		for(i=0;i<=len3;i++)
			dp[0][0][i] = 0;
		
		for(i=1;i<=len2;i++){
			for(j=1;j<=len1;j++){
				for(k=1;k<=len3;k++){
			
				if(str2[i-1] == str1[j-1] && str1[j-1] == str3[k-1] )
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				else
					dp[i][j][k] = max( dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1] ) ); 
			
			
				}
				
			}
		}
			cout<<dp[len2][len1][len3]<<endl;
	}
	return 0;
}


