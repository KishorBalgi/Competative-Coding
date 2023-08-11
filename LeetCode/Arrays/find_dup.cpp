// https://leetcode.com/problems/find-the-duplicate-number/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0,f=0,a=0;
        // Slow and Fast
        do{
            s=nums[s];
            f=nums[nums[f]];
        }while(s!=f);

        while(s!=a){
            s=nums[s];
            a=nums[a];
        }
        return nums[s];
    }
};

int main(){
    Solution sol;
    vector<int> nums={3,3,2,1,4};
    cout<<sol.findDuplicate(nums)<<endl;
    return 0;
}