// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root,vector<int>& nodes){
        if(!root) return;
        
        inorder(root->left,nodes);
        
        nodes.push_back(root->data);
        
        inorder(root->right,nodes);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> nodes;
       inorder(root1,nodes);
       inorder(root2,nodes);
       
       int n=nodes.size();
       int gap=n/2 + n%2;
       
       while(gap>0){
           int i=0,j=i+gap;
           
           while(j<n){
               if(nodes[i]>nodes[j]){
                   swap(nodes[i],nodes[j]);
               }
               i++;
               j++;
           }
           if(gap==1) break;
           gap=gap/2 + gap%2;
       }
       
       return nodes;
    }
};