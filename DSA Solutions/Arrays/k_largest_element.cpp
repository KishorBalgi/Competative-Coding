// https://leetcode.com/problems/kth-largest-element-in-an-array

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        // Create a min heap:
        priority_queue<int,vector<int>,greater<int>> pq;

        // Push the first k elements into priority queue:
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }

        // Now we go on replacing smaller elements with larger elments from remaingin array:
        for(int i=k;i<n;i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};

int main(){
    Solution sol;
    vector<int> nums={3,2,1,5,6,4};
    cout<<sol.findKthLargest(nums,6)<<endl;
    return 0;
}