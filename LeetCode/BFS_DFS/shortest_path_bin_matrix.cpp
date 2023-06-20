// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// DFS solution gives TLE:
// class Solution {
// public:
//     int minPath=INT_MAX,n=0,m=0;
//     void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int length,int i,int j){
//         if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]!=0) return;

//         if(i==n-1 && j==m-1){
//             minPath=min(minPath,length+1);
//         }
//         if(length+1>minPath) return;
//         visited[i][j]=1;
//         dfs(grid,visited,length+1,i,j+1);
//         dfs(grid,visited,length+1,i+1,j+1);
//         dfs(grid,visited,length+1,i+1,j);
//         dfs(grid,visited,length+1,i+1,j-1);
//         dfs(grid,visited,length+1,i,j-1);
//         dfs(grid,visited,length+1,i-1,j-1);
//         dfs(grid,visited,length+1,i-1,j);
//         dfs(grid,visited,length+1,i-1,j+1);
//         visited[i][j]=0;
//     } 
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//         vector<vector<int>> visited(m, vector<int>(n,0));
//         dfs(grid,visited,0,0,0);
//         if(minPath==INT_MAX) return -1;
//         return minPath;
//     }
// };

// BFS:
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),len=0;
        int dirX[]={0,1,1,1,0,-1,-1,-1};
        int dirY[]={1,1,0,-1,-1,-1,0,1};

        queue<pair<int,int>> tiles;
        tiles.push({0,0});

        if(grid[0][0]==1) return -1;

        while(!tiles.empty()){
            int size=tiles.size();
            len++;

            while(size--){
                int x=tiles.front().first;
                int y=tiles.front().second;

                if(x==n-1 && y==m-1){
                    return len;
                }
                tiles.pop();

                for(int i=0;i<8;i++){
                    int newX=x+dirX[i];
                    int newY=y+dirY[i];

                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==0){
                        grid[newX][newY]=1;
                        tiles.push({newX,newY});
                    }
                }
            }
        }

        return -1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid={
        {0,1},{1,0}
    };
    cout<<sol.shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}