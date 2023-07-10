// https://leetcode.com/problems/next-permutation/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int j=-1,temp=0;

        // Find the break point from left i.e, where the prev ele is less then the next ele:
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                j=i;
                break;
            }
        }
        
        // Swap the break point with the next largest element form the right side:
        if(j>-1){
            for(int i=n-1;i>j;i--){
                if(nums[i]>nums[j]){
                    temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                    break;
                }
            }
        }

        // reverse the right side:
        reverse(nums.begin()+j+1,nums.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,4,3};
    sol.nextPermutation(nums);
    for(int i : nums) cout<<i<<" ";
    return 0;
}