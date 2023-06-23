// https://leetcode.com/problems/house-robber/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int i){
        if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];
        // If i is selected:
        int a=nums[i]+solve(nums,dp,i+2);

        // If i is not selected:
        int b=solve(nums,dp,i+1);

        dp[i]=max(a,b);

        return dp[i]; 
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        solve(nums,dp,0);
        return dp[0];
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,7,3,3,9,1,1};
    cout<<sol.rob(nums)<<endl;
    return 0;
}