// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> nodes;
        queue<pair<Node *,int>> heights;
        vector<int> bottomView;
        heights.push({root,0});
        // Applying BFS:
        
        while(!heights.empty()){
            Node * cur=heights.front().first;
            // Verticle Height:
            int vh = heights.front().second;
            
            nodes[vh]=cur->data;
            
            if(cur->left) heights.push({cur->left,vh-1});
            if(cur->right) heights.push({cur->right,vh+1});
            
            heights.pop();
        }
        
        for(auto node: nodes){
            bottomView.push_back(node.second);
        }
        
        return bottomView;
    }
};