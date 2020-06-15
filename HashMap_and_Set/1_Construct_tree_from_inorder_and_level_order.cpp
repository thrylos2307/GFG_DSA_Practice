#include <bits/stdc++.h>
#include<set> 
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node* makeNode(int data){ 
    node* newNode = new node(); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 

class Tree{
	node *root;
	public:
		Tree(){
			root = NULL;
		}
	
	void makeTree(int in[], int level[] , int start,int end,int n );
	node* getTree(int in[], int level[] , int start, int end, int n );
	void printInorder();
	void printInorder(node* );
};

void Tree::printInorder(){
	printInorder(root);
}

void Tree::printInorder(struct node* curr){
	if(curr==NULL)
		return;
	printInorder(curr->left);
	cout<<curr->data<<" ";
	printInorder(curr->right);
}

void Tree::makeTree(int in[], int level[], int start, int end, int n){
	root = getTree(in,level,0,n-1,n);
}

struct node* Tree::getTree(int in[], int level[], int start, int end, int n){
	if (n <= 0) return NULL;
	
	node* top = makeNode(level[0]);
//	cout<<"Done"<<endl;
	int indx = -1,i;
	
	for(i=start;i<=end;i++){
		if(level[0] == in[i])
		{
			indx = i;
			break;
		}
	}
	
	set<int> s;
	for(i = start;i<indx;i++)
		s.insert(in[i]);
	
	int left [s.size()];
	int right[end-start-s.size()];
	
	int li = 0, ri = 0;
	for(int i=1;i<n;i++){
		if(s.find(level[i])!= s.end()){
		
			left[li]  = level[i];
			li++;}
		else
		{
			right[ri]  = level[i];
			ri++;	
		}	
	}
	
	top->left = getTree(in , left , start , indx-1, indx-start);
	top->right = getTree(in, right, indx+1, end, end-indx);
	
	return top;
	
}


int main(){
	int n,i;
	cin>>n;
	int in[n], level[n];
	
	for(i=0;i<n;i++)
		cin>>in[i];
	
	for(i=0;i<n;i++)
		cin>>level[i];
		
	Tree root;
	
	root.makeTree(in,level,0,n-1,n);
//	cout<<"Done!";
	root.printInorder();
	
	
}
