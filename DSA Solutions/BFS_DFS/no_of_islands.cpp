#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int n,m;
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        if(i<0 || j<0 || i==m || j==n) return;
        if(visited[i][j]==1 || grid[i][j]!='1') return;
        visited[i][j]=1;

        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j-1);
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid={{'1','1','1'},
    {'0','1','0'},{'1','1','1'}
};
    cout<<s.numIslands(grid)<<endl;
    return 0;
}