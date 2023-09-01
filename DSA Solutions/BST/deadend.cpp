// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

void findAllNodes(Node* root,set<int>& allNodes){
    if(!root) return;
    
    allNodes.insert(root->data);
    findAllNodes(root->left,allNodes);
    findAllNodes(root->right,allNodes);
}
bool solve(Node* root,set<int>& allNodes){
    if(!root) return false;
    
    if(!root->left && !root->right){
        int pre=root->data - 1 ;
        int nxt=root->data + 1 ;
        return (allNodes.find(pre)!=allNodes.end()) && (allNodes.find(nxt)!=allNodes.end());
    }
    
    return solve(root->left,allNodes) or solve(root->right,allNodes);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    if(!root) return false;
    set<int> allNodes;
    allNodes.insert(0);
    findAllNodes(root,allNodes);
    return solve(root,allNodes);
}