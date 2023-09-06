// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    bool getPath(Node* root,vector<int>& path,int target){
        if(!root) return false;
        
        path.push_back(root->data);
        
        if(root->data==target) return true;
        
        if(getPath(root->left,path,target) || getPath(root->right,path,target)) return true;
        
        path.pop_back();
        
        return false;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        vector<int> p1,p2;
        getPath(root,p1,a);
        getPath(root,p2,b);
        
        int i=0,n=p1.size(),m=p2.size();
        
        while(i<n && i<m && p1[i]==p2[i]){
            i++;
        }
        // cout<<p1.size()<<" "<<p2.size()<<" "<<i;
        return (p1.size()-i) + (p2.size()-i);
    }
};