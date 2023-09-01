// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
    int preIndex=0;
    TreeNode* solveTree(vector<int>& preorder, vector<int>& inorder,int s,int e) {
        if(s>=e) return NULL;
        TreeNode* root=new TreeNode(preorder[preIndex++]);
        cout<<root->val<<endl;
        // Find the position of the root in inorder traversal:
        int rootPos=0; 
        for(int i=s;i<e;i++){
            if(root->val==inorder[i]){
                rootPos=i;
                break;
            }
        }
        root->left=solveTree(preorder,inorder,s,rootPos);
        root->right=solveTree(preorder,inorder,rootPos+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solveTree(preorder,inorder,0,inorder.size());
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
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    TreeNode* root=sol.buildTree(preorder,inorder);
    printTree(root);
    
    return 0;
}