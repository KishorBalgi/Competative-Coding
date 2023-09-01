// https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/

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
    ListNode* zigzag(ListNode* head,bool flag) {

        if(!head || !head->next){
            return head;
        }

        if(flag==1){
            if(head->val > head->next->val)
                swap(head->val,head->next->val);
            return zigzag(head->next,!flag);
        }else{
            if(head->val < head->next->val)
                swap(head->val,head->next->val);
            return zigzag(head->next,!flag);
        }
    }
};

int main(){
    Solution sol;
    // create a linked list:
    ListNode* head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    // print the original linked list
    ListNode* ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";

    sol.zigzag(head,1);

    // print the reversed linked list
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    return 0;
}