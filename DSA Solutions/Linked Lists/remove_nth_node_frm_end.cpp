// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//  Definition for singly-linked list.
#include<iostream>
#include<stack>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;

        for(int i=1; i<=n;i++){
            fast=fast->next;
        }

        while(fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }

        slow->next=slow->next->next;
        return start->next;
    }
};

int main(){
    Solution sol;
    // create a linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n=2;

    // print the original linked list
    ListNode* ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";

    // call the reverseList function
    head=sol.removeNthFromEnd(head,n);

    // print the reversed linked list
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    return 0;
}