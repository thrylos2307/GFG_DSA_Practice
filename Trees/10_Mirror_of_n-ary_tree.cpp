#include <bits/stdc++.h> 
using namespace std;

struct Node{
	int data;
	list<Node*> children;
};

class Tree{
public:
	
	Node* root;
	
	Tree(){
		root = NULL;
	}


	void insert(int x,int y);
	void insert(Node*,int x,int y);

	void print();
};


void Tree::insert(int x,int y){
	insert(root,x,y);
}

void Tree::insert(Node* curr,int x,int y){
	
	if(curr==NULL){
		Node* temp = new Node;
		temp->data = y;
	
		root = new Node;
		root->data = x;
		root->children.push_back(temp);
		return;
	}
	
	queue<Node*> q;
	q.push(curr);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		
		if(temp->data==x){
		Node* child = new Node;
		child->data = y;
		
		temp->children.push_back(child);
		return;}
		
		else{
			list<Node*> l = temp->children;
			
			for(list<Node*>::iterator it = l.begin(); it!= l.end();it++){
				q.push(*it);
			}
		}	
	}		
}

stack<int> makeStack(Node* curr,stack<int> s){
	if(curr==NULL)
		return s;
	
	s.push(curr->data);
	for(list<Node*>::iterator it = curr->children.begin();it!=curr->children.end();it++){
		s = makeStack(*it,s);
	}
	return s;
}

queue<int> makeQueue(Node* curr,queue<int> q){
	if(curr==NULL)
		return q;
	
	for(list<Node*>::iterator it = curr->children.begin();it!=curr->children.end();it++){
		q = makeQueue(*it,q);
	}
	q.push(curr->data);
	return q;
}

bool check(Node* first,Node* second){
	stack<int> s;
	queue<int> q;
	
	s = makeStack(first,s);
	q = makeQueue(second,q);
	
	while(!s.empty()&&!q.empty()){
		if(s.top()!=q.front())
			return false;
		else{
			s.pop();
			q.pop();
		}
	}
	return true;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		
		Tree tree1;
		Tree tree2;
		
		int n,e,i,x,y;
		cin>>n>>e;
		for(i=0;i<e;i++){
			cin>>x>>y;
			tree1.insert(x,y);
		}
		for(i=0;i<e;i++){
			cin>>x>>y;
			tree2.insert(x,y);
		}
		cout<<check(tree1.root,tree2.root)<<endl;
	}
	return 0;	
}

