// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

//  Definition for singly-linked list.
#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
        if(!a){
            return b;
        }else if(!b){
            return a;
        }
        
        if(a->val<=b->val){
            a->next=merge(a->next,b);
            return a;
        }else{
            b->next=merge(a,b->next);
            return b;
        }
    }
    ListNode* middleNode(ListNode* node){
        ListNode* slow=node;
        ListNode* fast=node->next;
        
        while(fast && fast->next){
            
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    ListNode* mergeSort(ListNode* head) {
        // your code here
        if(!head->next) return head;
        
        ListNode* head1=head;
        ListNode* middle=middleNode(head);
        ListNode* head2=middle->next;
        middle->next=NULL; 
        
        head1=merge(mergeSort(head1),mergeSort(head2));
        
        return head1;
    }
    
};

int main(){
    Solution sol;

    ListNode* head=NULL;

    // List 1:
    ListNode* list1 = new ListNode(3);
    list1->next = new ListNode(5);
    list1->next->next = new ListNode(4);
    list1->next->next->next = new ListNode(2);
    list1->next->next->next->next = new ListNode(1);

    // print the original linked list
    ListNode* ptr = list1;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";


    // call the reverseList function
    head = sol.mergeSort(list1);

    // print the reversed linked list
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    return 0;
}