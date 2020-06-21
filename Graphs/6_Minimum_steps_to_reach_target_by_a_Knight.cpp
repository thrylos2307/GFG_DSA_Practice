#include <bits/stdc++.h>
using namespace std;

bool valid(int x,int y, int n){
	
	if(x>=0&&x<n && y>=0 && y<n)
		return true;
	
	return false;
}

int minSteps(int n,int kx,int ky,int tx,int ty){
	int board[n][n];
	memset(board,-1,sizeof(board));
	
	board[kx][ky] = 0;
	
	queue<pair<int, int> > q;
	q.push(make_pair(kx,ky));
	
	int moves[2][8] = {{-2, -1, 1, 2, -2, -1, 1, 2},{-1, -2, -2, -1, 1, 2, 2, 1}};
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		
		for(int i=0;i<8;i++){
			
			if( valid(x+moves[0][i] , y+moves[1][i] , n ) && board[x+moves[0][i]][y+moves[1][i]] == -1){
				board[x+moves[0][i]][y+moves[1][i]] = board[x][y] + 1;
				q.push( make_pair(x+moves[0][i] , y+moves[1][i]) );
			}
			
		}
		q.pop();
		
	}
	return board[tx][ty];
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,kx,ky,tx,ty;
		cin>>n>>kx>>ky>>tx>>ty;
		
		int ans = minSteps(n,kx-1,ky-1,tx-1,ty-1);
		
		if(ans == -1)
			cout<<0<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
