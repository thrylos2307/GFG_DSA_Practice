#include <bits/stdc++.h> 
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

//////////////////////////////////////

class Tree{
	node *root;
	public:
		Tree(){
			root = NULL;
		}
	int isempty(){
		return (root==NULL);
	}
	
	void insert(int item);
	void delNode(int key);
	void delNode(node*,int key);
	void delDeepNode(node*,node*);
	
	void printInorder();
	void printPreorder();
	void printPostorder();
	
	void printInorder(node* );
	void printPreorder(node* );
	void printPostorder(node* );
};

//////////////////////////////////////

void Tree::insert(int item){
		
	node *p = new node;
	p->data = item;
	p->left = NULL;
	p->right =NULL;

	if(isempty()){
		root = p;
	}
	else{
		
		queue<node*> q;
		q.push(root);
		
		while(!q.empty()){
			node* temp = q.front();
			q.pop();
			
			if(!temp->left){
				temp->left = p;
				break;
			}
			else
				q.push(temp->left);
			
			if(!temp->right){
				temp->right = p;
				break;
			}
			else
				q.push(temp->right);
			
		}				
	}
}

/////////////////////////////////

void Tree::printInorder(){
	printInorder(root);
}

void Tree::printPreorder(){
	printPreorder(root);
}

void Tree::printPostorder(){
	printPostorder(root);
}

void Tree::printInorder(struct node* curr){
	if(curr==NULL)
		return;
	printInorder(curr->left);
	cout<<curr->data<<" ";
	printInorder(curr->right);
}

void Tree::printPreorder(struct node* curr){
	if(curr==NULL)
		return;
	cout<<curr->data<<" ";
	printPreorder(curr->left);
	printPreorder(curr->right);
}

void Tree::printPostorder(struct node* curr){
	if(curr==NULL)
		return;
	printPostorder(curr->left);
	printPostorder(curr->right);
	cout<<curr->data<<" ";
}

/////////////////////////////////


void Tree::delDeepNode(node* curr, node* del){
	queue<struct node*> q;
	q.push(curr);
	
	struct node* temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == del){
			temp = NULL;
			delete (del);
			return;
		}
		if(temp->right){
			if(temp->right == del)
			{
				temp->right = NULL;
				delete (del);
				return;
			}
			else
				q.push(temp->right);
		}
		
		if(temp->left){
			if(temp->left == del)
			{
				temp->left = NULL;
				delete (del);
				return;
			}
			else
				q.push(temp->left);
		}
		
		
	}
	
}


void Tree::delNode(node* curr, int key){
	if(curr == NULL)
		return;
	if(curr->left == NULL && curr->right == NULL){
		if(curr->data == key)
			delete(curr);
		else
			return;
			
		return;
	}
	
	queue<struct node*> q;
	q.push(curr);
	
	struct node* deep; //will store the deepest node
	struct node* del_node = NULL; //will store the node to be deleted
	
	while(!q.empty()){
		deep = q.front();
		q.pop();
		
		if(deep->data == key)
			del_node = deep;
		
		if(deep->left)
			q.push(deep->left);
		if(deep->right)
			q.push(deep->right);
	}
	
	if(del_node != NULL){
		int var = deep->data;
		delDeepNode(root,deep);
		del_node->data = var;
	}
	return;
}


void Tree::delNode(int key){
	delNode(root,key);
}

////////////////////////////////

int main(){
	Tree root;
	root.insert(1);
	root.insert(2);
	root.insert(3);
	root.insert(4);
	root.insert(5);
	root.insert(6);
	root.insert(7);
	root.insert(8);
	root.insert(9);

	root.printInorder();
	cout<<endl;
	root.printPreorder();
	cout<<endl;
	root.printPostorder();
	
	return 0;
}
