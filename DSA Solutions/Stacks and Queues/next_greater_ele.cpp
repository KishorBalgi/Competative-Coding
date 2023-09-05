// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> res;
        stack<long long> s;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            
            if(s.empty()) res.insert(res.begin(),-1);
            else res.insert(res.begin(),s.top());
            s.push(arr[i]);
        }

        
        return res;
    }
};