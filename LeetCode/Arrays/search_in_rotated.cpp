// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,m,p,n=nums.size(),h=n-1,lft,rgt;
        if(nums[l]<nums[h]){
            p=0;
        }
        else 
            while(l<=h){
                m=(l+h)/2;
                if(m==0 || nums[m]>nums[m+1]){
                    p=m+1;
                    break;
                }else if(m==h || nums[m]<nums[m-1]){
                    p=m;
                    break;
                }else if(nums[l]<nums[m]){
                    l=m+1;
                }else{
                    h=m-1;
                }
            }
        cout<<p<<endl;
        lft=binarySearch(nums,0,p-1,target);
        rgt=binarySearch(nums,p,n-1,target);
        return lft!=-1?lft:rgt;
    }
    int binarySearch(vector<int>& nums,int l,int h ,int target){
        int m;
        // cout<<l<<" "<<h<<endl;
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==target){
                return m;
            }else if(target<nums[m])
                h=m-1;
            else    
                l=m+1;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> a={2,3,5,8,9};
    cout<<s.search(a,9)<<endl;
    return 0;
}