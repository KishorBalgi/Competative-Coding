// https://leetcode.com/problems/copy-list-with-random-pointer/

class Solution {
public:
    Node* solve(Node* node,unordered_map<Node*,Node*>& nodeMap){
        if(!node) return NULL;

        Node* newNode=new Node(node->val);
        nodeMap[node]=newNode;
        if(node->random){
            if(nodeMap[node->random]) newNode->random=nodeMap[node->random];
            else newNode->random=solve(node->random,nodeMap);
        }

        if(node->next){
            if(nodeMap[node->next]) newNode->next=nodeMap[node->next];
            else newNode->next=solve(node->next,nodeMap);
        }

        return newNode;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> nodeMap;
        return solve(head,nodeMap);
    }
};