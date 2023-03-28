// https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),count,longest;
        set<int> temp;
        vector<int> v;
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i : nums){
            temp.insert(i);
        }
        for(auto i: temp){
            v.push_back(i);
        }
        count=longest=1;
        for(int i=1;i<v.size();i++){
            if(abs(v[i]-v[i-1])==1){ 
                count++;
            }else{
                count=1;
            }
            if(count>longest) longest=count;
        }
        return longest;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,0,1};
    int res=s.longestConsecutive(nums);
    cout<<res<<endl;
    return 0;
}