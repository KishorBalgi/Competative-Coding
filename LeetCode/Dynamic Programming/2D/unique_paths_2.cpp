// https://leetcode.com/problems/unique-paths-ii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size(),val=1;
        if(obstacleGrid[0][0]==1) return 0;
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1) val=0;
            obstacleGrid[0][i]=val;
        }
        val=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1) val=0;
            obstacleGrid[i][0]=val;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) obstacleGrid[i][j]=0;
                else obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        for(auto v: obstacleGrid){
            for(int i: v) cout<<i<<" ";
            cout<<endl;
        }
        return obstacleGrid[m-1][n-1];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> obstacleGrid={
        {1},
        {0},
    };
    // vector<vector<int>> obstacleGrid={
    //     {0,0,0},
    //     {0,1,0},
    //     {0,0,0}
    // };
    cout<<sol.uniquePathsWithObstacles(obstacleGrid)<<endl;
    return 0;
}