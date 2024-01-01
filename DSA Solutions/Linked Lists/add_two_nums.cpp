// https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head=new ListNode(), * cur = head;
        ListNode * p1=l1, * p2=l2;

        int c=0,s=0;

        while(p1!=NULL && p2!=NULL){
            s=p1->val + p2->val + c;
            ListNode * newNode= new ListNode(s%10);
            cur->next=newNode;
            cur=cur->next;
            // carry:
            c=s/10;
            p1=p1->next;
            p2=p2->next;
        }

        while(p1!=NULL){
            s=p1->val + c;
            // cout<<s<<endl;
            ListNode * newNode= new ListNode(s%10);
            // cout<<s<<"\t"<<newNode->val<<endl;
            cur->next=newNode;
            cur=cur->next;
            // carry:
            c=s/10;
            p1=p1->next;
        }

        while(p2!=NULL){
            s=p2->val + c;
            // cout<<s<<endl;
            ListNode * newNode= new ListNode(s%10);
            // cout<<s<<"\t"<<newNode->val<<endl;
            cur->next=newNode;
            cur=cur->next;
            // carry:
            c=s/10;
            p2=p2->next;
        }

        if(c!=0){
            ListNode * newNode= new ListNode(c);
            cur->next=newNode;
        }

        return head->next;
    }
};

int main(){
    Solution sol;

    ListNode* head=NULL;

    // List 1:
    ListNode* list1 = new ListNode(9);
    list1->next = new ListNode(9);
    list1->next->next = new ListNode(9);
    list1->next->next->next= new ListNode(9);

    // List 2:
    ListNode* list2 = new ListNode(9);
    list2->next = new ListNode(9);
    list2->next->next = new ListNode(9);

    // print the original linked list
    ListNode* ptr = list1;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";

    ptr = list2;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";

    // call the reverseList function
    head = sol.addTwoNumbers(list1,list2);

    // print the reversed linked list
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    return 0;
}
