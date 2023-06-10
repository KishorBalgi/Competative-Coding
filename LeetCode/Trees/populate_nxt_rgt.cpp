// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include<iostream>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            int n=nodeQueue.size();
            cout<<n<<endl;
            while(n--){
                Node * front=nodeQueue.front();
                nodeQueue.pop();
                cout<<n<<" "<<front<<endl;
                if(!nodeQueue.empty() && n>0) front->next=nodeQueue.front();
                else front->next=NULL;

                if(front->left) nodeQueue.push(front->left);
                if(front->right) nodeQueue.push(front->right);
            }
        }

        return root;
    }
};

int main(){
    Solution sol;
    Node* node7=new Node(7);
    Node* node6=new Node(6);
    Node* node5=new Node(5);
    Node* node4=new Node(4);
    Node* node3=new Node(3,node6,node7,NULL);
    Node* node2=new Node(2,node4,node5,NULL);
    Node* root=new Node(1,node2,node3,NULL);
    root=sol.connect(root);
    // while(root!=NULL){
    //     cout<<root->val<<"->";
    //     root=root->next;
    // }
    return 0;
}
