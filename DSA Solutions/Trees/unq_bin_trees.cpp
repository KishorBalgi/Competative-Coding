// https://leetcode.com/problems/unique-binary-search-trees/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(dp[n]!=0) return dp[n];

        for(int i=1;i<=n;i++){
            int sum=solve(i-1,dp)*solve(n-i,dp);
            dp[n]+=sum;
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n+2,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        return solve(n,dp);
    }
};

int main(){
    Solution sol;
    cout<<sol.numTrees(10)<<endl;
    return 0;
}