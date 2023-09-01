// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include<iostream>
#include<vector>
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
    vector<int> result;
    void postorder(TreeNode * node){
        if(!node) return;
        postorder(node->left);
        postorder(node->right);
        result.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return result;
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* root =new TreeNode(1,NULL,new TreeNode(2,new TreeNode(3),NULL));

    for(int i:sol.postorderTraversal(root)) cout<<i<<" ";
    return 0;
}