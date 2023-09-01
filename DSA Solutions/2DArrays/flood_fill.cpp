// https://leetcode.com/problems/flood-fill/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int pixelVal,int color){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=pixelVal ) return;

        image[i][j]=color;
        dfs(image,i,j+1,pixelVal,color);
        dfs(image,i,j-1,pixelVal,color);
        dfs(image,i+1,j,pixelVal,color);
        dfs(image,i-1,j,pixelVal,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> image={
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    for(vector<int> v: sol.floodFill(image,1,1,2)){
        for(int i: v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}