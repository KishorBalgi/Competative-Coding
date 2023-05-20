// https://leetcode.com/problems/merge-k-sorted-lists/

//  Definition for singly-linked list.
#include<iostream>
#include<vector>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * l1=list1,* l2=list2;

        if(l1 == NULL){
            return list2;
        }

        if(l2 == NULL){
             return list1;
        }

        if(l1->val < l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        
        while(lists.size()!=1){
            vector<ListNode *> newLists;

            for(int i=0;i<lists.size();i+=2){
                ListNode * l1=lists[i];
                ListNode * l2=i+1!=lists.size()?lists[i+1]:NULL;
                newLists.push_back(mergeTwoLists(l1,l2));
            }

            lists=newLists;
        }

        return lists[0];
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

    // List 2:
    ListNode* list2 = new ListNode(3);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(5);
    list2->next->next->next = new ListNode(7);

    // List 3:
    ListNode* list3 = new ListNode(5);
    list3->next = new ListNode(7);
    list3->next->next = new ListNode(9);
    list3->next->next->next = new ListNode(11);

    // List 4:
    ListNode* list4 = new ListNode(3);
    list4->next = new ListNode(4);
    list4->next->next = new ListNode(7);
    list4->next->next->next = new ListNode(11);
    list4->next->next->next->next = new ListNode(15);
    list4->next->next->next->next->next = new ListNode(16);


    // print the original linked list
    printList(list1);
    printList(list2);
    printList(list3);
    printList(list4);

    vector<ListNode *> lists = {list1,list2,list4};
    // call the reverseList function
    head = sol.mergeKLists(lists);

    // print the reversed linked list
    printList(head);
    return 0;
}