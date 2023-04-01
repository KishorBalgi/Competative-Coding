// https://leetcode.com/problems/search-a-2d-matrix/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),l,mid,h;
        for(int i=0;i<m;i++){
            if(target>matrix[i][n-1]){
                continue;
            }
            l=0; h=n-1;
            while(l<=h){
                mid=(l+h)/2;
                if(matrix[i][mid]==target){
                    return true;
                }else if(target<matrix[i][mid]){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<s.searchMatrix(matrix,18)<<endl;
    return 0;
}