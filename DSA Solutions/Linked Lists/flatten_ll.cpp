// https://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/

//  Definition for singly-linked list.
#include<iostream>
#include<queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode *child;
     ListNode() : val(0), next(nullptr), child(nullptr) {}
     ListNode(int x) : val(x), next(nullptr), child(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next), child(nullptr) {}
     ListNode(int x, ListNode *next,ListNode* child) : val(x), next(next), child(child) {}
};

class Solution {
    public:
    // Space Complexity: O(n) Time Complexity: O(n)
    ListNode* flattenList(ListNode* head){
        queue<ListNode*> children;
        children.push(head);
        ListNode* temp;
        head=temp;

        while(!children.empty()){
            ListNode* front = children.front();
            temp->next=front;
            while(front){
                if(front->child) {
                    children.push(front->child);
                    front->child=NULL;
                }
                temp=front;
                front=front->next;
            }
            children.pop();
        }

        return head->next;
    }

    // Space Complexity: O(1) Time Complexity: O(n)
    ListNode* flattenList2(ListNode* head){
        ListNode* start, * end;
        start=head;
        end=head;

        while(start){
            if(start->child){
                while(end->next){
                    end=end->next;
                }
                end->next=start->child;
            }
            start=start->next;
        }

        return head;
    }

    
};

int main(){
    Solution sol;

    ListNode* head=NULL;

    // List 1:
    ListNode* list1 = new ListNode(10);
    list1->next = new ListNode(5);
    list1->next->next = new ListNode(12);
    list1->next->next->next= new ListNode(7);
    list1->next->next->next->next= new ListNode(11);

    // List 2:
    ListNode* list2 = new ListNode(4);
    list2->next = new ListNode(20);
    list2->next->next = new ListNode(13);

    // List 3:
    ListNode* list3 = new ListNode(17);
    list3->next = new ListNode(6);

    // List 4:
    ListNode* list4 = new ListNode(2);


    // List 5:
    ListNode* list5 = new ListNode(16);

    // List 7:
    ListNode* list7 = new ListNode(9);
    list7->next = new ListNode(8);

    // List 8:
    ListNode* list8 = new ListNode(3);

    // List 9:
    ListNode* list9 = new ListNode(19);
    list9->next = new ListNode(15);

    // Add Children:
    list1->child=list2;
    list1->next->next->next->child=list3;

    list2->next->child=list4;
    list2->next->next->child=list5;

    list3->child = list7;

    list5->child=list8;

    list7->child=list9;
    // call the reverseList function
    head = sol.flattenList(list1);

    // print the reversed linked list
    ListNode* ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    
    // call the reverseList function
    head = sol.flattenList2(list1);

    // print the reversed linked list
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
    return 0;
}