// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),start=0,end=n-1,mid=0;

        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target && nums[mid]>target){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                if(nums[end]>=target && nums[mid]<target){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> a={1,3,5};
    cout<<s.search(a,5)<<endl;
    return 0;
}