// https://leetcode.com/problems/jump-game/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // bool jump(vector<int>& nums,int i){
    //     if(i==nums.size()-1 || nums[i]==-1) return true;
    //     if(nums[i]==0) return false;

    //     for(int j=1;j<=nums[i];j++){
    //         if(jump(nums,i+j)){
    //             nums[i]=-1;
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // bool canJump(vector<int>& nums) {
    //     return jump(nums,0);
    // }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxReach=0;
        for(int i=0;i<n;i++){
            if(maxReach==n-1) return true;
            
            if(i>maxReach) 
                return false;
            else 
                maxReach=max(maxReach,i+nums[i]);
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums={3,2,1,0,4};
    cout<<sol.canJump(nums)<<endl;
    return 0;
}