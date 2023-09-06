// https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/1

class Solution{
  public:
    void inorderArr(vector<pair<int,int>>& inorder,vector<int>&A,int i){
        int n=A.size(),left=2*i+1,right=2*i+2;
        if(left<n) inorderArr(inorder,A,left);
        inorder.push_back({A[i],i});
        if(right<n) inorderArr(inorder,A,right);
    }
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        int swaps=0;
        vector<pair<int,int>> inorder;
        inorderArr(inorder,A,0);
        sort(A.begin(),A.end());
        for(int i=0;i<n;i++){
            if(A[i]!=inorder[i].first){
                swap(inorder[i],inorder[inorder[i].second]);
                swaps++;
                i--;
            }
        }
        return swaps;
    }
    
    
};