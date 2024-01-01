// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include<iostream>
#include<set>
using namespace std;

struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0,c2=0,offset=0;
        ListNode* ptr=headA;

        while(ptr){
            c1++;
            ptr=ptr->next;
        }

        ptr=headB;

        while(ptr){
            c2++;
            ptr=ptr->next;
        }

        offset=abs(c1-c2);

        if(c1>c2){
            while(offset--){
                headA=headA->next;
            }
        }else{
            while(offset--){
                headB=headB->next;
            }
        }

        while(headA){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;

    }
};