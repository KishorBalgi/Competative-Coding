// https://leetcode.com/problems/balanced-binary-tree/

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
    bool res=true;
    int solve(TreeNode * root){
        if(root==NULL) return 0;
        int leftHeight=solve(root->left);
        int rightHeight=solve(root->right);
        if(abs(leftHeight-rightHeight)>1) res=false;
        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return res;
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* root =new TreeNode(1,new TreeNode(2,new TreeNode(4,new TreeNode(6),new TreeNode(7)),new TreeNode(5)),new TreeNode(3));

    cout<<sol.isBalanced(root); 
    return 0;
}