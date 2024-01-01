// https://leetcode.com/problems/next-greater-node-in-linked-list/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res(1,0);
        stack<pair<int,int>> nodes;
        nodes.push({head->val,0});
        ListNode* ptr=head->next;
        int i=1;

        while(ptr){
            while(!nodes.empty() && ptr->val>nodes.top().first){
                res[nodes.top().second]=ptr->val;
                nodes.pop();
            }
            nodes.push({ptr->val,i});
            res.push_back(0);
            ptr=ptr->next;
            i++;
        }
        return res;
    }
};