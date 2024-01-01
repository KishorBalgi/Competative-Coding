/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head,*prev,*temp;
        // Find the mid using Floyd Cycle detection:
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // Reverse the end half:
        prev=slow;
        slow=slow->next;
        prev->next=NULL;
        while(slow){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        // Compare first half with reversed second reversed half:
        fast=head;
        slow=prev;
        while(slow && fast){
            if(fast->val!=slow->val) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }

    // bool isPalindrome(ListNode* head) {
    //     ListNode* ptr=head;
    //     ListNode* top=NULL;
    //     stack<ListNode*> rev;
    //     while(ptr!=NULL){
    //         rev.push(ptr);
    //         ptr=ptr->next;
    //     }
    //     ptr=head;
    //     while(!rev.empty()){
    //         top=rev.top();
    //         if(ptr->val!=top->val) return false;
    //         rev.pop();
    //         ptr=ptr->next;
    //     }
    //     return true;
    // }
};