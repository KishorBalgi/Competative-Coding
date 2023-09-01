// https://leetcode.com/problems/linked-list-cycle-ii/

#include<iostream>
#include<set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                // We have found the node where the fast and slow pointer's meet 
                // but that is not the start of the cycle. To find the start of 
                // Cycle we have to start from head with slow ptr and the current
                // intersection of the ptrs and move one step at a time to detect
                // the start node of the cycle.
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};