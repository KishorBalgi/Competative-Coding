// https://leetcode.com/problems/linked-list-cycle/

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
    // Using HashSet O(n):
    // bool hasCycle(ListNode *head) {
    //     set<ListNode *> nodeSet;
    //     ListNode * ptr = head;
    //     while(ptr != NULL){
    //         nodeSet.insert(ptr);
    //         if(nodeSet.find(ptr->next)!=nodeSet.end()){
    //             return true;
    //         }
    //         ptr=ptr->next;
    //     }
    //     return false;
    // }

    // Floyd's Tortoise and Hare Algorithm:
    bool hasCycle(ListNode *head) {
        ListNode * s, * f;
        s=head;
        f=head;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f){
                return true;
            }
        }
        return false;
    }
};