// https://leetcode.com/problems/matrix-diagonal-sum/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res=0;
        int n=mat.size();
        // For Primary Diagonal:
        for(int i=0;i<n;i++){
            res+=mat[i][i];
            res+=mat[i][n-i-1];
        }
        if(n%2!=0){
            res-=mat[n/2][n/2];
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<sol.diagonalSum(mat)<<endl;
    return 0;
}