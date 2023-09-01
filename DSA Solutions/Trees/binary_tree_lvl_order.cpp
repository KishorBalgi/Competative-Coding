// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> result;
    queue<TreeNode *> nodeQueue;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return result;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int size=nodeQueue.size();
            vector<int> level;
            while(size--){
                TreeNode * front=nodeQueue.front();
                if(front->left)
                    nodeQueue.push(front->left);
                if(front->right)
                    nodeQueue.push(front->right);
                level.push_back(front->val);
                nodeQueue.pop();
            }
            result.push_back(level);
        }
        return result;
    }
};

int main(){
    Solution sol;
    // Create the nodes
    TreeNode* root =new TreeNode(3,new TreeNode(9),new TreeNode(20,new TreeNode(15),new TreeNode(7)));

    for(vector<int> v: sol.levelOrder(root)){
        for(int i : v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}