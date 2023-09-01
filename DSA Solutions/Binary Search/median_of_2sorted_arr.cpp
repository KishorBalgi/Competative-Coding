// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(),i=0,j=0,mid=(m+n)/2;
        vector<int> sortedArr;
        while(i<m && j<n && sortedArr.size()<=mid){
            if(nums1[i]<=nums2[j]){
                sortedArr.push_back(nums1[i++]);
            }else{
                sortedArr.push_back(nums2[j++]);
            }
        }
        while(i<m && sortedArr.size()<=mid){
            sortedArr.push_back(nums1[i++]);
        }
        while(j<n && sortedArr.size()<=mid){
            sortedArr.push_back(nums2[j++]);
        }
        if((m+n)%2==0){
            return (float)(sortedArr[mid-1]+sortedArr[mid])/2;
        }
        return (float)sortedArr[mid];
    }
};

int main(){
    Solution s;
    vector<int> nums1={1,2},nums2={3,4};
    cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}