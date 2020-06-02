#include <bits/stdc++.h> 
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

class BinTree{
	node* root;
	public:
		BinTree(){
			root = NULL;
		}
		int isEmpty(){
		
			return (root==NULL);}
			
		node* getMin(node* curr)
		{
			while(curr->left != NULL) curr = curr->left;
			return curr;
		}	
		
		void insert(int key);
		
		void printLevelOrder();
		void printLevelOrder(node*);
		
		void del(int key);
		struct node* del(node* curr, int key);
		
		void printInorder();
		void printPreorder();
		void printPostorder();
	
		void printInorder(node* );
		void printPreorder(node* );
		void printPostorder(node* );
		
		void search(int key);
		void search(node*,int key);
		
		bool checkBST();
		bool checkBST(node*,int,int);
		
		void makeNonBST(){
			node* p = new node();
			p->data = 2;
			p->left =NULL;
			p->right = NULL;
			root->right->right->right = p;
		}
		
};

///////////////////////////
//----------Insert---------

void BinTree::insert(int key){
	node* p = new node;
	p->data = key;
	p->left = NULL;
	p->right = NULL;
	
	if(isEmpty())
		root = p;
		
	else{
		node* curr =root;
		node* prev = NULL;
		
		while(curr!=NULL){
			if(key<curr->data){
				prev = curr;
				curr = curr->left;}
			else if(key>=curr->data){
				prev = curr;
				curr = curr->right;}
		}
		
		if(key<prev->data)
			prev->left = p;
		else
			prev->right = p;
		
	}
	
}

/////////////////////////////
//---------Deletion----------

void BinTree::del(int key){
	root = del(root,key);
}

struct node* BinTree::del(node* curr, int data){
	if(curr==NULL) 
		return curr;
	
	else if(data < curr->data) 
		curr->left = del(curr->left,data);
	
	else if(data > curr->data) 
		curr->right = del(curr->right,data);
	
	else{
		if(curr->left==NULL && curr->right==NULL){
			delete curr;
			curr = NULL;
		}
		
		else if(curr->left == NULL){
			struct node* temp = curr;
			curr = curr->right;
			delete temp;
		}
		
		else if(curr->right == NULL){
			struct node* temp = curr;
			curr = curr->left;
			delete temp;
		}
		
		else{
			struct node* temp = getMin(curr->right);
			curr->data = temp->data;
			curr->right = del(curr->right,temp->data);
				
		}		
	}
	return curr;
}

/////////////////////////////
//---Level Order Traversal---

void BinTree::printLevelOrder(){
	printLevelOrder(root);
}

void BinTree::printLevelOrder(node* curr){
	if(curr== NULL)
		return;
	
	queue<node*> q;
	q.push(curr);
	
	while(!q.empty()){
		node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left !=NULL)
			q.push(temp->left);
			
		if(temp->right !=NULL)
			q.push(temp->right);			
	}
}

/////////////////////////////
//--------Traversal--------

void BinTree::printInorder(){
	printInorder(root);
}

void BinTree::printPreorder(){
	printPreorder(root);
}

void BinTree::printPostorder(){
	printPostorder(root);
}

void BinTree::printInorder(struct node* curr){
	if(curr==NULL)
		return;
	printInorder(curr->left);
	cout<<curr->data<<" ";
	printInorder(curr->right);
}

void BinTree::printPreorder(struct node* curr){
	if(curr==NULL)
		return;
	cout<<curr->data<<" ";
	printPreorder(curr->left);
	printPreorder(curr->right);
}

void BinTree::printPostorder(struct node* curr){
	if(curr==NULL)
		return;
	printPostorder(curr->left);
	printPostorder(curr->right);
	cout<<curr->data<<" ";
}

/////////////////////////////
//----------Search----------

void BinTree::search(int key){
	search(root,key);
}

void BinTree::search(node* curr,int key){
	if(curr== NULL)
		return;
	
	queue<node*> q;
	q.push(curr);
	
	while(!q.empty()){
		node* temp = q.front();
		if(temp->data == key){
			cout<<"Found!";
			return;}
			
		q.pop();
		if(temp->left !=NULL)
			q.push(temp->left);
			
		if(temp->right !=NULL)
			q.push(temp->right);
				
	}
	cout<<"Not found!";
	return;
	
}

/////////////////////////////
//--------Check BST---------

bool BinTree::checkBST(){
		return checkBST(root,INT_MIN,INT_MAX);
}

bool BinTree::checkBST(node* curr,int min,int max){
	if(curr==NULL)
		return true;
	
	if(curr->data < min || curr->data > max)
		return false;
	
	return ( checkBST(curr->left, min, curr->data)&&checkBST(curr->right, curr->data, max) );
}

/*
bool BinTree::checkBST(node* curr){
	if(curr==NULL){
		cout<<"Null"<<endl;
		return false;
	}
	else{
		queue<node*> q;
		q.push(curr);
		
		while(!q.empty()){
			node* temp = q.front();
			q.pop();
			
			if(!temp->left && !temp->right){
				return true;
			}
			else{
				if(temp->right){
				
				if(temp->data > temp->right->data)
					return false;
				}
				
				if(temp->left){
				
				if(temp->data < temp->left->data)
					return false;
					
				}
				v 
				else if( (!checkBST(temp->left)) || (!checkBST(temp->right)) )
					return false;
			}
		}
		return true;
	}
}
*/


/////////////////////////////
int main(){
	BinTree root;
	root.insert(8);
	root.insert(6);
	root.insert(7);
	root.insert(10);
	root.insert(9);
	root.insert(9);
	root.insert(4);
	root.insert(5);
	root.insert(11);
//	root.makeNonBST();
	root.printInorder();
	cout<<endl;
	root.printPreorder();
	cout<<endl;
	root.printPostorder();
	cout<<endl;
	root.printLevelOrder();
	root.del(9);
	cout<<endl;
	root.printLevelOrder();
	root.del(11);
	cout<<endl;
	root.printLevelOrder();
	root.del(6);
	cout<<endl;
	root.printLevelOrder();
	cout<<endl;
	root.search(9);
	cout<<endl;
	root.search(2);
	cout<<endl;
	cout<<root.checkBST();

	
	
	return 0;
}
