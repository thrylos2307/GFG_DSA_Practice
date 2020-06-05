
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should print right view of tree
// A wrapper over leftViewUtil()
map<int,int> m;


void printLevelOrder(struct Node* curr,int level){
	if(curr== NULL)
		return;
	
	queue<pair<Node*, int> > q;
	q.push(pair<Node*,int>(curr,level));
	m.insert(pair<int,int>(level,curr->data));
	
	while(!q.empty()){
		pair<Node*, int> p = q.front();
		Node* temp = p.first;
		int l = p.second;
	//	cout<<temp->data<<" ";
		
		q.pop();
		
			if(temp->right !=NULL)
		{
			q.push(pair<Node*,int>(temp->right,l+1));
			m.insert(pair<int,int>(l+1,temp->right->data));
		}
		if(temp->left !=NULL)
			{
			q.push(pair<Node*,int>(temp->left,l+1));
			m.insert(pair<int,int>(l+1,temp->left->data));
		}
	
				
	}
	
}

void rightView(Node *root)
{
   printLevelOrder(root,0);
    
    for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
    	cout<<it->second<<" ";
	}
	m.clear();
}
