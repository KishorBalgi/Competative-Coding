// https://leetcode.com/problems/maximum-product-subarray/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),maxPLeft=-11,maxPRight=-11,prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            maxPLeft=max(maxPLeft,prod);
            if(prod==0) prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            maxPRight=max(maxPRight,prod);
            if(prod==0) prod=1;
        }
        return max(maxPRight,maxPLeft);
    }
};

int main(){
    Solution sol;
    vector<int> nums={3,-1,4};
    cout<<sol.maxProduct(nums)<<endl;
    return 0;
}