// https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),count;
        set<int> num_set;
        for(int i : nums){
            num_set.insert(i);
        }
        int longest=0,cur_num,cur_cnt;
        for(int num : nums){
            if(num_set.count(num-1)==0){
                cur_num=num;
                cur_cnt=1;
                while(num_set.count(cur_num+1)>0){
                    cur_num++;
                    cur_cnt++;
                }
                longest=max(longest,cur_cnt);
            }
        }
        return longest;
    }
};

int main(){
    Solution s;
    vector<int> nums={0,3,7,2,5,8,4,6,0,1};
    int res=s.longestConsecutive(nums);
    cout<<res<<endl;
    return 0;
}