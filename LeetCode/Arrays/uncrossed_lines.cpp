// https://leetcode.com/problems/uncrossed-lines/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int  rec(int i,int j,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp){
        if(i==nums1.size() || j==nums2.size()) return 0;
        int count=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]){
            count=1+rec(i+1,j+1,nums1,nums2,dp);
        }else{
            count=max(rec(i+1,j,nums1,nums2,dp),rec(i,j+1,nums1,nums2,dp));
        }
        dp[i][j]=count;
        return count;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return rec(0,0,nums1,nums2,dp);
    }
};

int main(){
    Solution sol;
    vector<int> nums1={2,5,1,2,5},nums2={10,5,2,1,5,2};
    cout<<sol.maxUncrossedLines(nums1,nums2)<<endl;
    return 0;
}