// https://leetcode.com/problems/rotate-array/?envType=study-plan&id=algorithm-i
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> cpy;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cpy.push_back(nums[i]);
        }for(int i=0;i<n;i++){
            nums[(i+k)%n]=cpy[i];
        }
        for(int i:nums){
            cout<<i<<" ";
        }
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5,6,7};
    s.rotate(nums,3);
    return 0;
}