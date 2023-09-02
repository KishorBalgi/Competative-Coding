// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,max_ele=0;

        for(int i=1;i<nums.size();i++){
            if(nums[max_ele]==nums[i]) count++;
            else count--;

            if(count==0){
                count=1;
                max_ele=i;
            }
        }
        int max=nums[max_ele];

        count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max) count++;
        }

        if(count>nums.size()/2) return max;
        return -1;
    }
};