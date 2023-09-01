// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution
{
    public:
    void solve(Node* root,int k,int& c,int& res){
        if(!root || c>=k) return;
        
        solve(root->right,k,c,res);
        
        c++;
        
        if(c==k){
            res=root->data;
            return;
        }
        
        solve(root->left,k,c,res);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int c=0;
        int res=-1;
        
        solve(root,K,c,res);
        
        return res;
    }
};

class Solution
{
    public:
    void preOrder(Node* root,priority_queue<int,vector<int>,greater<int>>& pq){
        if(!root) return;
        
        if(root->data>pq.top()){
            pq.pop();
            pq.push(root->data);
        }
        preOrder(root->right,pq);
        preOrder(root->left,pq);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<K;i++){
            pq.push(0);
        }
        
        preOrder(root,pq);
        
        return pq.top();
    }
};

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        Solution ob;
        cout << ob.kthLargest( head, k ) << endl;
    }
    return 1;
}