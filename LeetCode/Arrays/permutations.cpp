// https://leetcode.com/problems/permutations/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backTracking(vector<int> nums,vector<int> temp){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i])==temp.end()){
                temp.push_back(nums[i]);
                backTracking(nums,temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp={};
        backTracking(nums,temp);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3};
    vector<vector<int>> res;
    res=s.permute(nums);
    for(auto v:res){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}