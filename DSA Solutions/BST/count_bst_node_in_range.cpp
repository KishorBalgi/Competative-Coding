// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      if(!root) return 0;
      int count=0;
      
      if(root->data>=l && root->data<=h) count++;
      
      count+=getCount(root->left,l,h);
      count+=getCount(root->right,l,h);
      
      return count;
    }
};