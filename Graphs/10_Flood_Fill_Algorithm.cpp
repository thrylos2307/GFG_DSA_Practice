// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool valid(int x,int y, int N,int M){
	
	if(x>=0&&x<N && y>=0 && y<M)
		return true;
	
	return false;
}

void findIslands(vector<int> A[], int N, int M, int x, int y, int l) {
    int moves[2][4] = {{-1, 1, 0, 0},{0, 0, 1, -1}};
	
  	bool vis[N][M];
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				
				vis[i][j] = false;
			}
		}
		
				vis[x][y] = true;
				int oldColor = A[x][y];
				A[x][y] = l;
				queue<pair<int, int> > q;
				q.push(make_pair(x,y));
				
				while(!q.empty()){
					pair<int,int> p = q.front();
					int x  = p.first;
					int y = p.second;
					
					for(int k=0;k<4;k++){
			
						if( valid(x+moves[0][k] , y+moves[1][k] , N,M ) && A[x+moves[0][k]][y+moves[1][k]] == oldColor){
						   if(vis[x+moves[0][k]][y+moves[1][k]] ==false){
						   		vis[x+moves[0][k]][y+moves[1][k]] = true;
								
						   		A[x+moves[0][k]][y+moves[1][k]] = l;
						   		q.push( make_pair(x+moves[0][k] , y+moves[1][k]) );
						   }
								
						}
			
					}
					q.pop();	
				}
		//cout<<count<<endl;
}

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
        int x,y,k;
        cin>>x>>y>>k;
        findIslands(A,N,M,x,y,k);

    for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				
				cout<<A[i][j]<<" ";
			}
		}
	cout<<endl;
}
    return 0;
}

