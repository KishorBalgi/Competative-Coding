// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),r=0,c=n-1;
        while(r<m && c>=0){
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) c--;
            else r++;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix={
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout<<sol.searchMatrix(matrix,31);
    return 0;
}