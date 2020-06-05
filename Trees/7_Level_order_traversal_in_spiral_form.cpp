void printLevelOrder(struct Node* curr){
	if(curr== NULL)
		return;
	int level = 0;
	
	queue<pair<Node*,int>> q;
	q.push(pair<Node*,int>(curr,level));
	stack<pair<int,int>> s;
	
	while(!q.empty()){
		pair<Node*,int> p= q.front();
		
		Node* temp = p.first;
		int l = p.second;
		
		if(!s.empty()){
		    pair<int,int> t = s.top();
		    if(l>t.second){
		        while(!s.empty())
		            {
		                t = s.top();
		                cout<<t.first<<" ";
		                s.pop();
		            }
		    }
		}
		
	    if(l%2 == 0)
	        s.push(pair<int,int>(temp->data,l));
		else
		    cout<<temp->data<<" ";
		    
		q.pop();
		if(temp->left !=NULL)
			q.push(pair<Node*,int>(temp->left,l+1));
			
		if(temp->right !=NULL)
			q.push(pair<Node*,int>(temp->right,l+1));
				
	}
	while(!s.empty())
		            {
		               pair<int,int> t = s.top();
		                cout<<t.first<<" ";
		                s.pop();
		            }
}

void printSpiral(Node *root)
{
    printLevelOrder(root);
    return;
}
