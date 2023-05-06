// https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        stack<ListNode *> prevStack;

        ListNode * ptr=head;
        ListNode * temp=NULL;
        while(ptr!=NULL){
            prevStack.push(ptr);
            ptr=ptr->next;
        }

        ptr=head;
        while(ptr!=NULL && ptr->next!=NULL){
            if(prevStack.empty()) break;
            temp=prevStack.top();
            prevStack.pop();
            prevStack.top()->next=NULL;

            temp->next=ptr->next;
            ptr->next=temp;
            ptr=temp->next;
        }
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

    // print the original linked list
    ListNode* ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";

    // call the reverseList function
    sol.reorderList(head);

    // print the reversed linked list
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    return 0;
}