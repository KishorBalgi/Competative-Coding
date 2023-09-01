// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode * reverseList(ListNode * prev,ListNode * next){
        if(!prev) return NULL;
        if(!next) return prev;
        if(!next->next){
            next->next=prev;
            prev->next=NULL;
            return next;
        }
        ListNode * head=reverseList(prev->next,next->next);
        next->next=prev;
        prev->next=NULL;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c=k;
        ListNode * ptr=head;
        while(c--){
            if(!ptr) return head;
            if(c!=0){
                ptr=ptr->next;
            }
        }
        ListNode * nextRevHead=reverseKGroup(ptr->next,k);
        ptr->next=NULL;
        ListNode * reversedSubList=reverseList(head,head->next);
        head->next=nextRevHead;
        return reversedSubList;
    }
};

void printList(ListNode * list){
    ListNode * ptr = list;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

int main(){
    Solution sol;

    ListNode* head=NULL;

    // List 1:
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);



    // print the original linked list
    printList(list1);

    // call the reverseList function
    // head = sol.reverseKGroup(list1,2);
    head = sol.reverseKGroup(list1,2);

    // print the reversed linked list
    printList(head);
    return 0;
}