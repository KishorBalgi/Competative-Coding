// https://leetcode.com/problems/rotting-oranges/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int m,n;
    queue<pair<int,int>> rottenOranges;
    int freshOranges=0;
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=-1;
        m=grid.size();
        n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    rottenOranges.push({i,j});
                }
                if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }

        if(freshOranges==0){
            return 0;
        }

        if(rottenOranges.empty()){
            return -1;
        }

        while(!rottenOranges.empty()){
            int size=rottenOranges.size();
            while (size--){
                pair<int,int> fr=rottenOranges.front();
                int i=fr.first;
                int j=fr.second;
                rottenOranges.pop();
                setRotten(grid,{i+1,j});
                setRotten(grid,{i,j+1});
                setRotten(grid,{i-1,j});
                setRotten(grid,{i,j-1});
            }
            minutes++;
        }
        if(freshOranges!=0) return -1;
        return minutes;
    }

    void setRotten(vector<vector<int>>& grid,pair<int,int> pos){
        int i=pos.first;
        int j=pos.second;
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1) return;
        grid[i][j]=2;
        rottenOranges.push(pos);
        freshOranges--;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid={{0,2}};
    cout<<s.orangesRotting(grid)<<endl;
    return 0;
}