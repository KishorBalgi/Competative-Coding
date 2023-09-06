// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    bool isSameTree(Node* a,Node* b){
        if(!a && !b) return true;
        if(!a || !b || a->data!=b->data) return false;
        
        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }
    void getChildren(Node* root,vector<Node*>& children){
        if(!root || (!root->left && !root->right)) return;
        
        children.push_back(root);
        getChildren(root->left,children);
        getChildren(root->right,children);
    }
    int dupSub(Node *root) {
         // code here
        vector<Node*> leftChildren,rightChildren;
        
        getChildren(root->left,leftChildren);
        getChildren(root->right,rightChildren);
    
        
        for(auto a:leftChildren){
            for(auto b:rightChildren){
                if(isSameTree(a,b)){
                    return 1;
                }
            }
        }
        return 0;
    }
    
};