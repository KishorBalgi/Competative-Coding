// https://leetcode.com/problems/maximum-subarray/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    // Kadane's Algorithm:
    int maxSubArray(vector<int>& nums) {
        int maxn,sum;
        int n=nums.size();
        maxn=sum=nums[0];
        for(int i=1;i<n;i++){
            if(sum<0) sum=nums[i];
            else sum+=nums[i];
            maxn=max(sum,maxn);
        }
        return maxn;
    }
};

int main(){
    Solution s;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    int res=s.maxSubArray(nums);
    cout<<res<<endl;
    return 0;
}
