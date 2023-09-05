// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> resSet;
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        int n=nums.size(),i=0,j=1,k=2,l=n-1;
        while(i<n-3){
            j=i+1;
            while(j<n-2){
                k=j+1; l=n-1;
                while(k<l){
                    long long sum=long(nums[i])+long(nums[j])+long(nums[k])+long(nums[l]);
                    if(sum==target){
                        resSet.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }else if(sum<target) k++;
                    else l--;
                }
                j++;
            }
            i++;
        }
        for(vector<int> quad: resSet) res.push_back(quad);
        return res;
    }
};