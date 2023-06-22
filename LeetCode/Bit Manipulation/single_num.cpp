// https://leetcode.com/problems/single-number/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i : nums){
            res^=i;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,2,1};
    cout<<sol.singleNumber(nums)<<endl;
    return 0;
}