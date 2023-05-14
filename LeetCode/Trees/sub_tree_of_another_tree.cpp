// https://leetcode.com/problems/subtree-of-another-tree/

#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val!=q->val) return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL) return false;

        if(isSameTree(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* p1 =new TreeNode(3,new TreeNode(4,new TreeNode(1),new TreeNode(2)),new TreeNode(5));
    TreeNode* q1 =new TreeNode(4,new TreeNode(1),new TreeNode(2));

    cout<<sol.isSubtree(p1,q1); 
    return 0;
}