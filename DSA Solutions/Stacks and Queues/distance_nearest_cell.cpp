// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size(),n=grid[0].size();
	    vector<vector<int>> dp(m,vector<int>(n,2000));
	    
	   // Top-right to bottom-left;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1) dp[i][j]=0;
	            else{
	                if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
	                if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
	            }
	        }
	    }
	    // Bottom-left to Top-right;
	    for(int i=m-1;i>=0;i--){
	        for(int j=n-1;j>=0;j--){
	           if(i<m-1) dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
	           if(j<n-1) dp[i][j]=min(dp[i][j],dp[i][j+1]+1);

	        }
	    }
	    return dp;
	}
};