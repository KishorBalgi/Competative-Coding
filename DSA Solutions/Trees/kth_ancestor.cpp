// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

bool getPath(Node* root,vector<int>& path,int target){
    if(!root) return false;
    
    path.push_back(root->data);
    
    if(root->data==target) return true;
    
    if(getPath(root->left,path,target) || getPath(root->right,path,target)) return true;
    
    path.pop_back();
    
    return false;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    vector<int> path;
    getPath(root,path,node);
    
    int i=path.size()-1;
    while(k--){
        i--;
    }
    
    if(i>=0) return path[i];
    return -1;
}