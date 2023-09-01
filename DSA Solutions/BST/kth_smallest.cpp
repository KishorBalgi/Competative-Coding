// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    void solve(TreeNode* root,int k,int& c,int& res){
        if(!root || c>=k) return;

        // Recursively traverse to left:
        solve(root->left,k,c,res);

        c++;

        if(c==k){
            res=root->val;
            return;
        }

        solve(root->right,k,c,res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int res=-1;
        solve(root,k,c,res);
        return res;
    }
};