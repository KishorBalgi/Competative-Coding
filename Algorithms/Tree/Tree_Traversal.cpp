// Tree Traversals:

#include<iostream>
#include<queue>
#include<stack>
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
    // Inorder: Use for sorting in BST
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

    // Preorder: Used to copy a tree
    void preorder(TreeNode* root){
        if(!root) return;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    // Postorder: Used to delete a tree
    void postorder(TreeNode* root){
        if(!root) return;
        postorder(root->right);
        postorder(root->left);
        cout<<root->val<<" ";
    }

    // DFS(Depth First Search):
    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        dfs(root->right);
        cout<<root->val<<" ";
    }

    // BFS(Breadth First Search) or Level Order Traversal: O(n^2)
    void bfs(TreeNode* root){
        int h=heightOfTree(root);
        
        for(int i=1;i<=h;i++){
            printCurrentLevel(root,i);
            cout<<endl;
        }
    }

    // Print current level:
    void printCurrentLevel(TreeNode* root,int level){
        if(!root) return;
        else if(level==1){
            cout<<root->val<<" ";
        }else{
            printCurrentLevel(root->left,level-1);
            printCurrentLevel(root->right,level-1);
        }
    }

    // BFS(Breadth First Search) or Level Order Traversal (Using Queue): O(n)
    void bfsQueue(TreeNode* root){
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

    // Reverse Level Order Traversal: O(n)
    void reverseLevelOrder(TreeNode* root){
        queue<TreeNode*> nodes;
        vector<int> revTrav;
        nodes.push(root);

        while(!nodes.empty()){
            int n=nodes.size();

            while(n--){
                TreeNode* front=nodes.front();
                if(front->right) nodes.push(front->right);
                if(front->left) nodes.push(front->left);
                revTrav.insert(revTrav.begin(),front->val);
                nodes.pop();
            }
        }
        
        for(int val: revTrav) cout<< val <<" ";
        cout<<endl;
    }

    // Left view of a Tree:
    void leftView(TreeNode* root){
        vector<int> res;
        if(!root) return;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int traversed=0,level=1;
        
        while(!nodes.empty()){
            int n = nodes.size();
            
            while(n--){
                TreeNode * front=nodes.front();
                
                if(front->left) nodes.push(front->left);
                if(front->right) nodes.push(front->right);
                
                if(traversed<level){
                    res.push_back(front->val);
                    traversed++;
                }
                nodes.pop();
            }
            level++;
        }
        
        for(int val: res) cout<<val<<" ";
        cout<<endl;
    }

    // Right view of a Tree:
    void rightView(TreeNode* root){
        vector<int> res;
        if(!root) return;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int traversed=0,level=1;
        
        while(!nodes.empty()){
            int n = nodes.size();
            
            while(n--){
                TreeNode * front=nodes.front();
                
                if(front->right) nodes.push(front->right);
                if(front->left) nodes.push(front->left);
                
                if(traversed<level){
                    res.push_back(front->val);
                    traversed++;
                }
                nodes.pop();
            }
            level++;
        }
        
        for(int val: res) cout<<val<<" ";
        cout<<endl;
    }

    // Zig-zag traversal:
    void zigZagTraversal(TreeNode* root){
        vector<int> res;
    	queue<TreeNode *> nodes;
    	stack<int> rightTrav;
    	nodes.push(root);
    	
    	bool order=false;
    	
    	while(!nodes.empty()){
    	    int n=nodes.size();
    	    
    	    while(n--){
    	        TreeNode* front=nodes.front();
    	        if(front->left) nodes.push(front->left);
    	        if(front->right) nodes.push(front->right);
    	        if(!order) res.push_back(front->val);
    	        else rightTrav.push(front->val);
    	        nodes.pop();
    	    }
    	    
    	    while(!rightTrav.empty()){
    	        res.push_back(rightTrav.top());
    	        rightTrav.pop();
    	    }
    	    order=!order;
    	}
    	
        for(int val: res) cout<<val<<" ";
        cout<<endl;
    }
};

int main(){
    Solution sol;
    // Tree:
    //         50
    //       /   \
    //      40    60
    //    /   \  /  \
    //   20  30 10  70
    TreeNode* node7=new TreeNode(70);
    TreeNode* node6=new TreeNode(10);
    TreeNode* node5=new TreeNode(30);
    TreeNode* node4=new TreeNode(20);
    TreeNode* node3=new TreeNode(60,node6,node7);
    TreeNode* node2=new TreeNode(40,node4,node5);
    TreeNode* root =new TreeNode(50,node2,node3);
    cout<<endl<<"Inorder Traversal: "<<endl;
    sol.inorder(root);
    cout<<endl<<"Preorder Traversal: "<<endl;
    sol.preorder(root);
    cout<<endl<<"Postorder Traversal: "<<endl;
    sol.postorder(root);
    cout<<endl<<"Depth First Search: "<<endl;
    sol.dfs(root);
    cout<<endl<<"Breadth First Search: "<<endl;
    sol.bfs(root);
    cout<<endl<<"Breadth First Search(Queue): "<<endl;
    sol.bfsQueue(root);
    cout<<endl<<"Reverse Level Order Traversal(Queue): "<<endl;
    sol.reverseLevelOrder(root);
    cout<<endl<<"Left View of the tree: "<<endl;
    sol.leftView(root);
    cout<<endl<<"Right View of the tree: "<<endl;
    sol.rightView(root);
    cout<<endl<<"Zig Zag Traversal: "<<endl;
    sol.zigZagTraversal(root);
    return 0;
}