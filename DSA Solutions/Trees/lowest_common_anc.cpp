// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    bool getPath(TreeNode* root,TreeNode* x,vector<TreeNode*>& path){
        if(root==NULL) return false;

        path.push_back(root);

        if(root==x) return true;

        if(getPath(root->left,x,path) || getPath(root->right,x,path)) return true;

        path.pop_back();

        return false;
    }
    // Find path for both p and q and check the path until the path has difference:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor=NULL;

        vector<TreeNode*> pathP;
        getPath(root,p,pathP);
        vector<TreeNode*> pathQ;
        getPath(root,q,pathQ);

        int i=0,j=0;
        while(i<pathP.size() && j<pathQ.size()){
            if(pathP[i]==pathQ[j]){
                ancestor=pathP[i];
            }else return ancestor;
            i++;
            j++;
        }

        return ancestor;
    }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(root==NULL) return NULL;

    //     if(root==p || root==q) return root;

    //     TreeNode * leftResult=lowestCommonAncestor(root->left,p,q);
    //     TreeNode * rightResult=lowestCommonAncestor(root->right,p,q);

    //     if(leftResult!=NULL && rightResult!=NULL) return root;
    //     else if(leftResult!=NULL && rightResult==NULL) return leftResult;
    //     else if(leftResult==NULL && rightResult!=NULL) return rightResult;
    //     else return NULL;
    // }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* root = new TreeNode(3);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(0);
    TreeNode* node7 = new TreeNode(8);
    TreeNode* node8 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(4);

    // Assign the child nodes to the parent nodes
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = node8;
    node4->right = node9;

    cout<<sol.lowestCommonAncestor(root,node2,node3)->val; 
    return 0;
}