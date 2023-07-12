// Mirror of a tree:

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
    // Mirror of a tree:
    void mirrorify(TreeNode* root,TreeNode** mirror){
        if(!root) return;

        *mirror=new TreeNode(root->val);
        mirrorify(root->left,&(*mirror)->right);
        mirrorify(root->right,&(*mirror)->left);
    }

    // Print Tree Level Order:
    void printTree(TreeNode* root){
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            int n=nodes.size();

            while(n--){
                TreeNode* front=nodes.front();
                cout<<front->val<<" ";
                if(front->left) nodes.push(front->left);
                if(front->right) nodes.push(front->right);
                nodes.pop();
            }

            cout<<endl;
        }
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

    cout<<"Original Tree:"<<endl;
    sol.printTree(root);

    TreeNode* mirror=NULL;

    sol.mirrorify(root,&mirror);

    cout<<"Mirror Tree:"<<endl;
    sol.printTree(mirror);

    return 0;
}