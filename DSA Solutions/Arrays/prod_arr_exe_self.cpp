// https://leetcode.com/problems/product-of-array-except-self/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int prod=1, zeros=count(nums.begin(),nums.end(),0);
        if(zeros>1) return res;

        for(auto i: nums){
            if(i!=0) prod*=i;
        }
        for(int i=0;i<nums.size();i++){
            if(zeros==1) res[i]=nums[i]==0?prod:0;
            else res[i]=prod/nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums={-1,1,0,-3,3},res;
    res= s.productExceptSelf(nums);
    for(int i: res){
        cout<<i<<" ";
    }
    return 0;
}