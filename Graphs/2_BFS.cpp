#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}
vector <int> bfs(vector<int> g[], int N) {
    vector<int> res;
    queue<int> q; // stores the next node to visit
		set<int> s; // stores visited nodes
			q.push(0);
			s.insert(0);
	
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			res.push_back(temp);
			for(vector<int>::iterator x = g[temp].begin(); x!=g[temp].end();x++)
			{
				if(s.find(*x)==s.end()){
				
					q.push(*x);
					s.insert(*x);
				}
			}
		}
		return res;
}
