// https://leetcode.com/problems/daily-temperatures/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> temperatures={73,74,75,71,69,72,76,73},res;
    res=s.dailyTemperatures(temperatures);
    for(int i: res){
        cout<<i<<" ";
    }
    return 0;
}