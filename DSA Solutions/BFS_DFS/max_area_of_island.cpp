#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int n,m,maxIslands=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    maxIslands=max(dfs(grid,visited,i,j),maxIslands);
                }
            }
        }
        return maxIslands;
    }
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j){
        if(i<0 || j<0 || i==m || j==n) return 0;
        if(visited[i][j]==1 || grid[i][j]!=1) return 0;
        visited[i][j]=1;

        return dfs(grid,visited,i-1,j)+
        dfs(grid,visited,i,j+1)+
        dfs(grid,visited,i+1,j)+
        dfs(grid,visited,i,j-1)+1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid={{1,1,1},
    {0,1,0},{1,1,1}
};
    cout<<s.maxAreaOfIsland(grid)<<endl;
    return 0;
}