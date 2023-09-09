// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> rotten;
        int m=grid.size(),n=grid[0].size(),count=0,freshCount=0,rottenCount=0;
        vector<vector<int>> dir={{0,-1},{0,1},{-1,0},{1,0}};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    rotten.push({i,j});
                if(grid[i][j]==1) freshCount++;
            }
        }
        
        while(!rotten.empty()){
            int curR=rotten.size();
            while(curR--){
                pair<int,int> front=rotten.front();
                
                for(int k=0;k<4;k++){
                    
                    int new_i = front.first + dir[k][0];
                    int new_j = front.second + dir[k][1];
                    
                    if(isValid(new_i,new_j,m,n) && grid[new_i][new_j]==1){
                        grid[new_i][new_j]=2;
                        rottenCount++;
                        rotten.push({new_i,new_j});
                    }
                }
                rotten.pop();    
            }
            count++;
        }
        
        if(freshCount == rottenCount) return count==0?0:count-1;
        
        return -1;
    }
};