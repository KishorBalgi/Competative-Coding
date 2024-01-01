// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    bool isValid(int m,int n,int sr,int sc){
        if(sr>=0 && sr<m && sc>=0 && sc<n) return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> pixels;

        int val = image[sr][sc];
        pixels.push({sr,sc});
        while(!pixels.empty()){
            pair<int,int> pixel = pixels.front();
            int i= pixel.first;
            int j=pixel.second;

            if(isValid(m,n,i,j) && !visited[i][j] && image[i][j]==val){
                visited[i][j] = 1;
                // Add all neighbours to queue;
                image[i][j] = color;
                
                pixels.push({i-1,j});
                pixels.push({i,j-1});
                pixels.push({i,j+1});
                pixels.push({i+1,j});
            }

            pixels.pop();
        }

        return image;
    }
};