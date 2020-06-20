#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<int> *adj;
public:
	Graph(int vertices){
		this->V = vertices;
		adj = new vector<int>[V];
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int shortestDist(int root,int dest){
		queue<int> q; // stores the next node to visit
		set<int> s; // stores visited nodes
		int dist[V];
		int pred[V];
		memset(dist,INT_MAX,sizeof(dist));
		memset(pred,INT_MAX,sizeof(pred));
		q.push(root);
		s.insert(root);
		//int dist = INT_MAX;
		dist[root] = 0;
		while(!q.empty()){
			int temp = q.front();
		
			q.pop();
			//cout<<temp<<" ";
			for(vector<int>::iterator x = adj[temp].begin(); x!=adj[temp].end();x++)
			{
				if(s.find(*x)==s.end()){
					if(*x==dest){
						pred[*x] = temp;
						stack<int> path;
						path.push(*x);
						
						while(path.top()!=root){
							int pre = path.top();
							path.push(pred[pre]);
						}
						cout<<"Path: ";
						while(!path.empty()){
						
							cout<<" -> "<<path.top();
							path.pop();}	
							
						return (dist[temp]+1);
					}
					q.push(*x);
					s.insert(*x);
					dist[*x] = dist[temp] + 1;
					pred[*x] = temp;
				}
			}		
    	}
    	return INT_MAX;
	}
};

int main(){
	int T;
	cin>>T;
	while(T--){
		int V,E,i;
		cin>>V>>E;
		Graph g(V);
		for(i=0;i<E;i++){
			int x,y;
			cin>>x>>y;
			g.addEdge(x,y);
		}
		
		int src;
		int dest;
		cout<<"\nEnter sourse and destination respectively\n";
		cin>>src>>dest;
		cout<<"\nDist: "<<g.shortestDist(src, dest)<<endl;	
	
	
	}	
	return 0;
}
/*
Input format: 
1
8 10
0 1
0 3
1 2
3 7
3 4
7 4
7 6
4 6
4 5
6 5
2 6
*/
