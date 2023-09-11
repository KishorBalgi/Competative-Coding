// https://leetcode.com/problems/top-k-frequent-elements/description/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> pq;
        for(int i: nums){
            m[i]++;
        }
        int j=k;
        for(auto i:m){
            pq.push({i.second,i.first});
        }

        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
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