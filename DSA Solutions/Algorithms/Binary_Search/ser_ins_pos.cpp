// https://leetcode.com/problems/search-insert-position/?envType=study-plan&id=algorithm-i
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l,m,h;
        l=0;
        h=nums.size()-1;
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==target){
                return m;
            }else if(target<nums[m]){
                h=m-1;
            }else{
                l=m+1;
            }
        }
        cout<<l<<" "<<h<<endl;
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,3,5,6,9};
    cout<<s.searchInsert(nums,4);
    return 0;
}