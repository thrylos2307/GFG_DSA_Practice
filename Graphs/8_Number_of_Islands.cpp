// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

bool valid(int x,int y, int N,int M){
	
	if(x>=0&&x<N && y>=0 && y<M)
		return true;
	
	return false;
}

int findIslands(vector<int> A[], int N, int M) {
    int moves[2][8] = {{-1, 1, 1, 0, -1, 1, 0, -1},{0, 0, 1, 1, 1, -1, -1, -1}};
	
  	bool vis[N][M];
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				
				vis[i][j] = false;
			}
		}
		int count = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
			if(A[i][j]==1 && !vis[i][j]){
				count++;
				vis[i][j] = true;
				queue<pair<int, int> > q;
				q.push(make_pair(i,j));
				
				while(!q.empty()){
					pair<int,int> p = q.front();
					int x  = p.first;
					int y = p.second;
					
					for(int k=0;k<8;k++){
			
						if( valid(x+moves[0][k] , y+moves[1][k] , N,M ) && A[x+moves[0][k]][y+moves[1][k]] == 1){
						   if(vis[x+moves[0][k]][y+moves[1][k]] ==false){
						   		vis[x+moves[0][k]][y+moves[1][k]] = true;
						   		/*
						   		for(int l=0;l<N;l++){
						   			cout<<endl;
									for(int s=0;s<M;s++){
										cout<<vis[l][s]<<" ";
										
									}
									
								} */
								
						   		
						   		q.push( make_pair(x+moves[0][k] , y+moves[1][k]) );
						   }
								
						}
			
					}
					q.pop();	
				}
				
			}
		    }		
		}
		
		return count;
		//cout<<count<<endl;
}
