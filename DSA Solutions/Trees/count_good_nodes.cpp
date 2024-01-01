// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

#include<iostream>
#include<vector>
#include<queue>
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
    int count=0;
    void dfs(TreeNode * node,int high){
        if(!node) return;
        if(node->val>=high) count++;

        dfs(node->left,max(high,node->val));
        dfs(node->right,max(high,node->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return count;
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* root =new TreeNode(3,new TreeNode(1,new TreeNode(3),NULL),new TreeNode(4,new TreeNode(1),new TreeNode(5)));

    cout<<sol.goodNodes(root)<<endl;
    return 0;
}