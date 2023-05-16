// https://leetcode.com/problems/subsets/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums,vector<int> subset,int i){
        if(i==nums.size()) return res.push_back(subset);

        // Include element at ith pos:
        subset.push_back(nums[i]);
        solve(nums,subset,i+1);
        // Exclude element at ith pos:
        subset.pop_back();
        solve(nums,subset,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,{},0);
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    for(vector<int> v : sol.subsets(nums)){
        for(int i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}