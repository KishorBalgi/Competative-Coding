// https://leetcode.com/problems/top-k-frequent-elements/description/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i: nums){
            m[i]++;
        }

        vector<pair<int,int>> p;
        for(auto it:m){
            p.push_back({it.second,it.first});
        }
        sort(p.rbegin(),p.rend());

        for(int i=0;i<k;i++){
            res.push_back(p[i].second);
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,1,1,2,2,3},res;
    int k= 3;
    res=s.topKFrequent(nums,k);
    for(int i : res){
        cout<<i<<" ";
    }
    return 0;
}