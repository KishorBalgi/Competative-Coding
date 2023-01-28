// https://leetcode.com/problems/move-zeroes/?envType=study-plan&id=algorithm-i

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int k,l,n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        k=0;
        l=n-1;
        for(int i=0;i<n;i++){
            if(temp[i]!=0){
                nums[k]=temp[i];
                k++;
            }else{
                nums[l]=temp[i];
                l--;
            }
        }
        for(int i:nums){
            cout<<i<<" ";
        }
    }
};

int main(){
    Solution s;
    vector<int> nums={0,1,0,3,12};
    s.moveZeroes(nums);
    return 0;
}