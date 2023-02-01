// https://leetcode.com/problems/combination-sum/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int> nums,vector<int> temp,int i,int trg){
        if(trg==0){
            res.push_back(temp);
            return;
        }
        if(trg<0 || i==nums.size()) return;
        temp.push_back(nums[i]);
        backtracking(nums,temp,i,trg-nums[i]);
        temp.pop_back();
        backtracking(nums,temp,i+1,trg);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtracking(candidates,temp,0,target);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> candidates={2,3,6,7};
    vector<vector<int>> res;
    res=s.combinationSum(candidates,7);
    for(auto v:res){
        for(auto i:v){
            cout<<i<< " ";
        }
        cout<<endl;
    }
    return 0;
}