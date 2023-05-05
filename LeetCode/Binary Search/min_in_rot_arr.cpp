// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot=findPivot(nums);
        return nums[pivot];
    }
    int findPivot(vector<int>& nums){
        int s=0,e=nums.size()-1,l=0,h=e,m;
        if(nums[s]<=nums[e]){
            return s;
        }
        while(l<=h){
            m=(l+h)/2;
            if(nums[s]<=nums[m]){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums={2,1};
    cout<<s.findMin(nums)<<endl;
    return 0;
}