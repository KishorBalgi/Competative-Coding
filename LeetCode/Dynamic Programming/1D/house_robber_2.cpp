// https://leetcode.com/problems/house-robber/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        int rob1=0,rob2=0;
        for(int i=0;i<n;i++){
            int temp=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());
        return max(solve(v1),solve(v2));
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3,1};
    cout<<sol.rob(nums)<<endl;
    return 0;
}