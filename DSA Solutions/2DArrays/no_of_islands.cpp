//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),count=0;
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        int n=grid.size(),m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]=='0') return;
        visited[i][j]=true;
        
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j-1);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i+1,j+1);
        dfs(grid,visited,i+1,j-1);
        dfs(grid,visited,i-1,j+1);
        dfs(grid,visited,i-1,j-1);
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}