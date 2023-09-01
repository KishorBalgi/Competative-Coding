// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* temp=new Node(0);
        
        temp->next=head;
        
        Node* curEven=temp;
        Node* prev=temp;
        Node* cur=head;
        
        while(cur){
            if(cur->data%2==0 && curEven->next!=cur){
                prev->next=cur->next;
                cur->next=curEven->next;
                curEven->next=cur;
                cur=prev->next;
                curEven=curEven->next;
            }else{
                if(cur->data%2==0 && curEven->next==cur){
                    curEven=curEven->next;
                }
                cur=cur->next;
                prev=prev->next;
            }
        }
        
        return temp->next;
    }
};

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}