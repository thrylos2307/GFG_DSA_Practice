/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should convert a given Binary tree to Doubly
// Linked List

Node* printInorderIter(Node* curr,Node** head_ref){
	stack <Node*> s;
	Node* temp = curr;
	bool flag = true;
	Node* head = new Node;
	Node* fix = new Node;

	while(!(temp == NULL) || !s.empty() ){
			while(temp != NULL){
				s.push(temp);
				temp = temp->left;
			}
			temp = s.top();
			s.pop();	
			if(flag)
			    {
			        head->data = temp->data;
			        head->left = NULL;
			        head->right = NULL;
			        fix  = head;
			        head_ref = &fix;  
			        flag = false;
			    }
			 else{ 
			     Node* t = newNode(temp->data);
			     t->left = head;
			     t->right = NULL;
			     head->right = t;
			     head = head->right;  
			 }
			temp = temp->right;		
	}
	return *head_ref;
}

void bToDLL(Node *root, Node **head_ref)
{ 
    *head_ref = printInorderIter(root,head_ref);
}
