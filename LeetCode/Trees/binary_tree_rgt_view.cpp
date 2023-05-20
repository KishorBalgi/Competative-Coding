// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if(!root) return result;

        queue<TreeNode *> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            int s=nodes.size(),i=s;

            while(i--){
                TreeNode * front=nodes.front();
                if(i==s-1){
                   result.push_back(front->val); 
                }
                if(front->right)
                    nodes.push(front->right);
                if(front->left)
                    nodes.push(front->left);
                nodes.pop();
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* root =new TreeNode(1,new TreeNode(2,NULL,new TreeNode(5)),new TreeNode(3));

    for(int i:sol.rightSideView(root)) cout<<i<<" ";
    return 0;
}