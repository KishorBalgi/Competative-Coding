// https://leetcode.com/problems/add-two-numbers-ii/

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
    // best method is to use stack and get sum from top || not so good method: reverse the lists add them and reverse again
public:
// This approach is fine but uses recursive stack(not recommended):
    int c=0;
    ListNode* addNode(ListNode* n1,ListNode* n2){
        if(n1==NULL || n2==NULL){
            return NULL;
        }
        ListNode* nextNode=addNode(n1->next,n2->next);
        int s=(n1->val+n2->val+c);
        c= s/10;
        ListNode* newNode=new ListNode(s%10);
        newNode->next=nextNode;
        return newNode;
    }
    ListNode* listOfZeros(int n,ListNode* list){
        if(n==0) return list;
        ListNode* node=new ListNode(0);
        node->next=listOfZeros(n-1,list);
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p1=l1, * p2=l2;
        int m=0,n=0;

        while(p1!=NULL){
            m++;
            p1=p1->next;
        }

        while(p2!=NULL){
            n++;
            p2=p2->next;
        }
        int count=abs(m-n);
        if(m<n) {
            l1=listOfZeros(count,l1);
        }else{
            l2=listOfZeros(count,l2);
        }
        ListNode* ptr = l2;
        while (ptr != NULL) {
            cout << ptr->val << "->";
            ptr = ptr->next;
        }
        cout << "NULL\n";

        ListNode* sumHead=addNode(l1,l2);
        if(c!=0){
            ListNode* node=new ListNode(c);
            node->next=sumHead;
            sumHead=node;
        }

        return sumHead;
    }
};

int main(){
    Solution sol;

    ListNode* head=NULL;

    // List 1:
    ListNode* list1 = new ListNode(7);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    list1->next->next->next= new ListNode(3);

    // List 2:
    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);
    list2->next->next->next= new ListNode(3);

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