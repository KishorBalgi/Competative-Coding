// https://leetcode.com/problems/validate-binary-search-tree/

#include<iostream>
#include<vector>
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
    // Space Complex Solution: O(n) and Time Complexity: O(n)
    vector<int> nodes;
    void inOrder(TreeNode * root){
        if(!root) return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i=0;i<nodes.size()-1;i++){
            if(nodes[i]>=nodes[i+1]) return false;
        }
        return true;
    }

    // Time Complexity : O(nlog(n))
    // bool isRootGreaterThanLeft(TreeNode * root,TreeNode * subNode){
    //     if(!subNode) return true;
    //     if(root->val<=subNode->val) return false;
    //     return isRootGreaterThanLeft(root,subNode->left) && isRootGreaterThanLeft(root,subNode->right);
    // }

    // bool isRootLessThanRight(TreeNode * root,TreeNode * subNode){
    //     if(!subNode) return true;
    //     if(root->val>=subNode->val) return false;
    //     return isRootLessThanRight(root,subNode->left) && isRootLessThanRight(root,subNode->right);
    // }
    // bool isValidBST(TreeNode* root) {
    //     if(!root) return true;
    //     if(isRootGreaterThanLeft(root,root->left) && isRootLessThanRight(root,root->right)){
    //         return isValidBST(root->left) && isValidBST(root->right);
    //     }
    //     return false;
    // }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(9);
    TreeNode* node8 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(5);

    // Assign the child nodes to the parent nodes
    node1->left = node2;
    node1->right = node3;
    // node2->left = node4;
    // node2->right = node5;
    // node3->left = node6;
    // node3->right = node7;
    // node5->left = node8;
    // node5->right = node9;

    cout<<sol.isValidBST(node1)<<endl;
    return 0;
}