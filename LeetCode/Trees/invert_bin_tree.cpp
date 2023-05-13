// https://leetcode.com/problems/invert-binary-tree/


#include<iostream>
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return root;
        TreeNode * temp=root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void printTree(TreeNode * node){
    queue<TreeNode *> q;
    q.push(node);
    while(!q.empty()){
        TreeNode * front=q.front();
        cout<<front->val<<"\t";
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
        q.pop();
    } 
}

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);

    // Assign the child nodes to the parent nodes
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    // Print the values of the tree nodes
    printTree(node1); 
    cout<<endl;      
    TreeNode * root= sol.invertTree(node1);
    printTree(root);       

    return 0;
}