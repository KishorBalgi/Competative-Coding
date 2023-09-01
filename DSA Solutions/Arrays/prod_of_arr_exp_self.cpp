// https://leetcode.com/problems/product-of-array-except-self/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> suffix(n,1),prefix(n,1),res(n,1);
    //     for(int i=1;i<n;i++){
    //         prefix[i]=nums[i-1]*prefix[i-1];
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         suffix[i]=nums[i+1]*suffix[i+1];
    //     }

    //     for(int i=0;i<n;i++){
    //         res[i]=suffix[i]*prefix[i];
    //     }
    //     return res;
    // }

    // More optimizes DP:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        for(int i=1;i<n;i++){
            res[i]=nums[i-1]*res[i-1];
        }
        int rightProd=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=rightProd;
            rightProd*=nums[i];
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    for(int i: sol.productExceptSelf(nums)) cout<<i<<" ";
    return 0;
}