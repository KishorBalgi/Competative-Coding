// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1 

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* buildBST(int pre[],int n,int start,int end){
        
        Node * root=newNode(pre[start]);
        int i=start+1;
        while(i<=end && pre[i]<pre[start]){
            i++;
        }
        i--;
        if(i!=start) root->left=buildBST(pre,n,start+1,i);
        i++;
        if(i<=end) root->right=buildBST(pre,n,i,end);
        
        return root;
    }
    void print(Node* n){
        if(!n) return;
        print(n->left);
        print(n->right);
        cout<<n->data<<" ";
    }
    Node* post_order(int pre[], int size)
    {
        //code here
        return buildBST(pre,size,0,size-1);
    }
};