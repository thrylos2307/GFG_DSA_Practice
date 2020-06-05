
// } Driver Code Ends


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that prints the bottom view.
map<int,int> m;
void printLevelOrderRev(struct Node* curr,int level){
	if(curr== NULL)
		return;
	
	queue<pair<Node*, int> > q;
	stack<pair<int,int>> s;
	
	q.push(pair<Node*,int>(curr,level));
	s.push(pair<int,int>(level,curr->data));
	
	while(!q.empty()){
		pair<Node*, int> p = q.front();
		Node* temp = p.first;
		int l = p.second;
		
		q.pop();
		
		if(temp->left !=NULL){
			q.push(pair<Node*,int>(temp->left,l-1));
			s.push(pair<int,int>(l-1,temp->left->data));
		}
		if(temp->right !=NULL)
		{
			q.push(pair<Node*,int>(temp->right,l+1));
			s.push(pair<int,int>(l+1,temp->right->data));
		}
				
	}
	while(!s.empty()){
		pair<int, int> p = s.top();
		int fir = p.first;
		int sec = p.second;
		m.insert(pair<int,int>(fir,sec));
		s.pop();
		}
	
}

void bottomView(Node *root)
{
    printLevelOrderRev(root,0);
    
    for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
    	cout<<it->second<<" ";
	}
	m.clear();
}
