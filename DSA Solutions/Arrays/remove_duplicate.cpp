// 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1,n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) nums[k++]=nums[i];
        }

        return k;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2};
    int k = sol.removeDuplicates(nums);
    cout<<"k ="<<k<<endl;
    for(int i=0;i<k;i++){ cout<<nums[i]<<endl;} 
    return 0;
}