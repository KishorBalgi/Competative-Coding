// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

void inorder(Node* root,vector<Node*>& nodes){
    if(!root) return;
    
    inorder(root->left,nodes);
    
    nodes.push_back(root);
    
    inorder(root->right,nodes);
}
Node* buildBST(vector<Node*>& nodes,int s,int e){
    if(s>e) return NULL;
    int m=(s+e)/2;
    // cout<<nodes[m]->data<<" "<<s<<" "<<e<<endl;
    Node* mid=nodes[m];
    
    mid->right=buildBST(nodes,s,m-1);
    mid->left=buildBST(nodes,m+1,e);
    
    return mid;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<Node*> nodes;
	inorder(root,nodes);
	return buildBST(nodes,0,nodes.size()-1);
}