// https://leetcode.com/problems/subsets-ii/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    set<vector<int>> res;
    void solve(vector<int>& nums,vector<int> subset,int i){
        if(i==nums.size()) {
            res.insert(subset);
            sort(subset.begin(),subset.end());
            return;
        }

        // Include element at ith pos:
        subset.push_back(nums[i]);
        solve(nums,subset,i+1);
        // Exclude element at ith pos:
        subset.pop_back();
        solve(nums,subset,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        solve(nums,{},0);
        vector<vector<int>> result;
        for(auto ele : res) result.push_back(ele);
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,2};
    for(vector<int> v : sol.subsetsWithDup(nums)){
        for(int i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}