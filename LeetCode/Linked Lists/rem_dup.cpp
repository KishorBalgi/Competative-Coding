// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include<iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        int prev=head->val;
        ListNode * posNode=head->next,* prevPos=head,* ptr=head->next;
        while(ptr!=NULL){
            if(ptr->val!=prev){
                prev=ptr->val;
                posNode->val=ptr->val;
                prevPos=posNode;
                posNode=posNode->next;
            }
            ptr=ptr->next;
        }
        prevPos->next=NULL;
        return head;
    }
};

int main(){
    Solution sol;
    // create a linked list:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // print the original linked list
    ListNode* ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";

    head = sol.deleteDuplicates(head);

    // print the reversed linked list
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    return 0;
}