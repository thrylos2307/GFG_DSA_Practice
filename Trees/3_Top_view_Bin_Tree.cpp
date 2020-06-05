#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree

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
		if(temp->left !=NULL)
			{
			q.push(pair<Node*,int>(temp->left,l-1));
			m.insert(pair<int,int>(l-1,temp->left->data));
		}
		if(temp->right !=NULL)
		{
			q.push(pair<Node*,int>(temp->right,l+1));
			m.insert(pair<int,int>(l+1,temp->right->data));
		}
				
	}
	
}



void topView(struct Node *root)
{
    printLevelOrder(root,0);
    
    for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
    	cout<<it->second<<" ";
	}
	m.clear();
}



