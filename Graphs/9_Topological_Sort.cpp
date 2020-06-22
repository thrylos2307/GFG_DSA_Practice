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
}

void tSortHelper(int i, bool visited[], stack<int>& s){
	visited[i] = true;
	
	for(vector<int>::iterator j = adj[i].begin(); j<adj[i].end(); j++){
		if(!visited[*j]){
			tSortHelper(*j, visited,s);
		}	
	}
	 
	s.push(i);
}

void topoSort(){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;
		
	stack<int> s;
		
	for(int i=0; i<V; i++){
		if(!visited[i])
			tSortHelper(i,visited,s);
	}
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
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
		
		cout<<"Topologically Sorted Graph: ";
		g.topoSort();
		cout<<endl;
	
	}	
	return 0;
}
