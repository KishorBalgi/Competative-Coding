// BST basic operations:
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

    // Searching:
    bool searchBST(TreeNode* root,int target){
        if(!root) return false;

        if(root->val==target) return true;

        if(target<root->val) return searchBST(root->left,target);

        return searchBST(root->right,target);
    }

    // Insertion:
    TreeNode* insertBST(TreeNode* root,int data){
        if(!root) {
            return new TreeNode(data);
        }

        if(root->val>data) root->left=insertBST(root->left,data);
        else root->right = insertBST(root->right,data);

        return root;
    }

    // Deletion:
    TreeNode* deletBST(TreeNode* root,int data){
        // If data not found:
        if(!root) return root;

        // If root != data:
        if(root->val>data) {
            root->left=deletBST(root->left,data);
            return root;
        }
        else if(root->val<data){
            root->right=deletBST(root->right,data);
            return root;
        }

        // If either left or right or both have no child:
        if(!root->left){
            TreeNode* temp=root->right;
            free(root);
            return temp;
        }else if(!root->right){
            TreeNode* temp=root->left;
            free(root);
            return temp;
        }

        // Root has both child:
        
        // Get the successor from the right side:
        TreeNode* sucParent=root;
        TreeNode* successor=root->right;

        // Find the successor and its parent:
        while(successor->left!=NULL){
            sucParent=successor;
            successor=successor->left;
        }

        // Now we know that the successor is the left most, so we can 
        // safely assign the right of successor to the left of its parent.
        // If there is no successor then parent(root) of right = successor of right.

        if(sucParent!=root){
            sucParent->left=successor->right;
        }else{
            sucParent->right=successor->right;
        }

        // Assign the value of successor to the root:
        root->val=successor->val;

        // Delete the successor:
        free(successor);
        return root;


    }
};

int main(){
    Solution sol;
    // BST:
    //         50
    //       /   \
    //      30    60
    //    /   \     \
    //   20  40     70
    //  /
    // 10
    TreeNode* node7=new TreeNode(70);
    TreeNode* node6=new TreeNode(10);
    TreeNode* node5=new TreeNode(40);
    TreeNode* node4=new TreeNode(20,node6,NULL);
    TreeNode* node3=new TreeNode(60,NULL,node7);
    TreeNode* node2=new TreeNode(30,node4,node5);
    TreeNode* root =new TreeNode(50,node2,node3);

    cout<<"Binary Search tree:"<<endl;
    sol.printTree(root);
    cout<<endl<<"Searching: "<<sol.searchBST(root,10)<<endl;

    cout<<endl<<"Inserting: "<<endl;
    sol.insertBST(root,90);
    sol.insertBST(root,45);
    // sol.insertBST(root,97);
    // sol.insertBST(root,55);
    sol.printTree(root);

    cout<<endl<<"Deleting: "<<endl;
    sol.deletBST(root,30);
    sol.printTree(root);
    return 0;
}