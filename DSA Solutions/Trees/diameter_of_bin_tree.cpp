// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int maxDia=0;
    int solve(TreeNode * node){
        if(node==NULL) return 0;
        int leftHeight=solve(node->left);
        int rightHeight=solve(node->right);
        maxDia=max(maxDia,leftHeight+rightHeight+1);
        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxDia-1;
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* root =new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(5)),new TreeNode(3));

    cout<<sol.diameterOfBinaryTree(root); 
    return 0;
}