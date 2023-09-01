// https://leetcode.com/problems/squares-of-a-sorted-array/?envType=study-plan&id=algorithm-i
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        vector<int> res;
        while(i<=j){
            if(pow(nums[i],2)>=pow(nums[j],2)){
                res.insert(res.begin(),pow(nums[i++],2));
            }else{
                res.insert(res.begin(),pow(nums[j--],2));
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums={-11,-3,2,3,11},res;
    res=s.sortedSquares(nums);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}