// https://leetcode.com/problems/combination-sum-ii/

#include<iostream>
#include<vector>
#include<algorithm>
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

        for(int j=i;j<nums.size();j++){
            if(j!=i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            backtracking(nums,temp,j+1,trg-nums[j]);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,temp,0,target);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> candidates={10,1,2,7,6,1,5};
    vector<vector<int>> res;
    res=s.combinationSum2(candidates,8);
    for(auto v:res){
        for(auto i:v){
            cout<<i<< " ";
        }
        cout<<endl;
    }
    return 0;
}