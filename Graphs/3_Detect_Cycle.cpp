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
	//	adj[v].push_back(u);
	}	
	bool isConnected(int i, vector<bool>& visited){
		queue<int> q; // stores the next node to visit
		 // stores visited nodes
		vector<int> parent (V,-1);
		visited[i]  =true;
		q.push(i);
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			for(vector<int>::iterator x = adj[u].begin(); x!=adj[u].end();x++)
			{
				if(!visited[*x]){
					visited[*x] = true;
					q.push(*x);
					parent[*x] = u;
				}
				else if(parent[u]!=*x)
					return true;
			}
		}
		return false;
	}
	
	
	bool isCyclic(){
		vector<bool> visited (V,false);
		
		for(int i=0; i <V;i++){
			if(!visited[i]&&isConnected(i,visited))
				return true;
	}
		return false;
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
		if(g.isCyclic())
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}	
	return 0;
}
