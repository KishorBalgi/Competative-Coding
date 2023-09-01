// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/?ref=lbp

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool hasPair(vector<int>& nums,int sum){
        int n=nums.size(),pivot=-1;
        int l=0,h=n-1,m;
        // Find the pivot element:
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]>nums[m+1]){
                pivot=m;
                break;
            }else if(nums[m]>=nums[0]){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        l=pivot+1,h=pivot;
        while(l!=h){
            if(nums[l]+nums[h]==sum) return true;
            else if(nums[l]+nums[h]<sum){
                l=(l+1)%n;
            }else{
                h=(n+h-1)%n;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums={11, 15, 26, 38, 9, 10};
    cout<<sol.hasPair(nums,45)<<endl;
    return 0;
}