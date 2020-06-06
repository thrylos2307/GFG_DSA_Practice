

int printPostorder(struct Node* curr){
	if(curr==NULL)
	    return 0;
	    
	if(!curr->left && !curr->right){
	    int temp = curr->data;
	    curr->data = 0;
	    return temp;
	}
		
	int l = printPostorder(curr->left);
	int r = printPostorder(curr->right);
	int temp = l+r+curr->data;
	curr->data = l+r;
	return temp;
	
}

void toSumTree(Node *node)
{
    printPostorder(node);
}

