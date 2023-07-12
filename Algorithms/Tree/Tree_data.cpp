// Tree Data:

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
    // Height of the tree:
    int heightOfTree(TreeNode* root){
        if(!root) return 0;
        return max(heightOfTree(root->left),heightOfTree(root->right))+1;
    }

    // Leaf Node:
    int leafNodes(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        return leafNodes(root->left)+leafNodes(root->right);
    }

    // Non Leaf Node:
    int nonLeafNodes(TreeNode* root){
        if(!root || (!root->left && !root->right)) return 0;

        return leafNodes(root->left)+leafNodes(root->right)+1;
    }
};

int main(){
    Solution sol;
    // Tree:
    //         50
    //       /   \
    //      40    60
    //    /   \     \
    //   20  30     70
    //         \
    //         10
    TreeNode* node7=new TreeNode(70);
    TreeNode* node6=new TreeNode(10);
    TreeNode* node5=new TreeNode(30,NULL,node6);
    TreeNode* node4=new TreeNode(20);
    TreeNode* node3=new TreeNode(60,NULL,node7);
    TreeNode* node2=new TreeNode(40,node4,node5);
    TreeNode* root =new TreeNode(50,node2,node3);
    cout<<endl<<"Height: "<<sol.heightOfTree(root)<<endl;

    cout<<endl<<"Leaf Nodes: "<<sol.leafNodes(root)<<endl;

    cout<<endl<<"Non Leaf Nodes: "<<sol.nonLeafNodes(root)<<endl;
    return 0;
}