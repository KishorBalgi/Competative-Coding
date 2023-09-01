// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m,l=0,h=nums.size()-1,left=-1,right=-1,temp;
        vector<int> res;
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==target){
                left=right=m;
                temp=chunkBinSearch(nums,0,m-1,target,false);
                left=temp!=-1?temp:left;
                temp=chunkBinSearch(nums,m+1,h,target,true);
                right=temp!=-1?temp:right;
                break;
            }else if(target>nums[m])
                l=m+1;
            else    
                h=m-1;
        }
        return res = {left,right};
    }
    int chunkBinSearch(vector<int>& nums,int l,int h,int trg,bool dir){
        int m,pos=-1;
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==trg){
                pos=m;
                if(dir)
                    l=m+1;
                else    
                    h=m-1;
            }else if(trg<nums[m])
                h=m-1;
            else    
                l=m+1; 
        }
        return pos;
    }
};

int main(){
    Solution s;
    vector<int> a={2,2},res;
    res=s.searchRange(a,2);
    for(auto i:res)
        cout<<i<<" ";

}