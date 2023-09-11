// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int> res;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<k;i++){
            pq.push(-1);
        }
        
        for(int i=0;i<n;i++){
            if(pq.top()<arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
            res.push_back(pq.top());
        }
        
        return res;
    }
};