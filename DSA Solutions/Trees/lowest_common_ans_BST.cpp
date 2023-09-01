// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<root->val && q->val>root->val){
            return root;
        }
        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* node1 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(9);
    TreeNode* node8 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(5);

    // Assign the child nodes to the parent nodes
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;

    cout<<sol.lowestCommonAncestor(node1,node2,node9)->val<<endl;
    return 0;
}