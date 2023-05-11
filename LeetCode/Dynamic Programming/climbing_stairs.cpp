// https://leetcode.com/problems/climbing-stairs/

#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev1=1,prev2=1,cur=1;
        for(int i=2;i<=n;i++){
            cur=prev1+prev2;
            prev1=prev2;
            prev2=cur;
        }
        return cur;
    }
};

int main(){
    Solution sol;
    cout<<sol.climbStairs(5)<<endl;
    return 0;
}