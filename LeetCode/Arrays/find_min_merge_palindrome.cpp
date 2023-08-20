// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int minMergeOperations(vector<int> nums){
        int i=0,j=nums.size()-1,merge,count=0;
        while(i<j){
            if(nums[i]==nums[j]){
                i++;
                j--;
            }else if(nums[i]<nums[j]){
                merge=nums[i]+nums[i+1];
                nums.erase(nums.begin()+i);
                nums[i]=merge;
                j--;
                count++;
            }else{
                merge=nums[j]+nums[j-1];
                nums.erase(nums.begin()+j);
                nums[--j]=merge;
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums={11,14,15,19};
    cout<<sol.minMergeOperations(nums)<<endl;
    return 0;
}