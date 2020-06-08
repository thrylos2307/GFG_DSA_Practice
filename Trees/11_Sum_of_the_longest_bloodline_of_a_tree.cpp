

//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function

int height(Node* curr){
	if(curr == NULL)
		return 0;
	if(curr->left == NULL && curr->right == NULL)
		return 0;
	else{
		return 1+max( height(curr->left) , height(curr->right) );
	}
}

int sum(Node* curr,int ht,int psum,int lev){
    if(curr==NULL)
        return 0;
    int csum = curr->data+psum;
    if(lev==ht){
        return csum;
    }
    if(!curr->left&&!curr->right){
        return -1;
    }
    
    int l = sum(curr->left,ht,csum,lev+1);
    int r = sum(curr->right,ht,csum,lev+1);
    if(l>r)
        return l;
    else
        return r;
}

int sumOfLongRootToLeafPath(Node* root)
{
	int ht = height(root);
//	cout<<"Height "<<ht<<endl;
    return sum(root,ht,0,0);
}
