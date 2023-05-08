// https://leetcode.com/problems/remove-element/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,n=nums.size(),j=n-1,k=0,buf;
        while(i<=j){
            while(i<n && nums[i]!=val){
                i++;
                k++;
            }
            while(j>=0 && nums[j]==val){
                j--;
            }
            if(j<=i) break;
            buf=nums[i];
            nums[i]=nums[j];
            nums[j]=buf;
        }
        return k;
    }
};

int main(){
    Solution sol;
    vector<int> nums={2};
    int k = sol.removeElement(nums,3);
    cout<<"k ="<<k<<endl;
    for(int i=0;i<k;i++){ cout<<nums[i]<<endl;} 
    return 0;
}