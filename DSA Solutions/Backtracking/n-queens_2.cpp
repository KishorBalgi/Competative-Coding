// https://leetcode.com/problems/n-queens/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int result=0;
    void solveQueen(vector<vector<int>>& board,int n,int r, int c){
        for(int i=0;i<r;i++){
            if(board[i][c]==1) return;
        }
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
            if(board[i][j]==1) return;
        }
        
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1) return;
        }

        board[r][c]=1;

        if(r==n-1){
            result++;
            board[r][c]=0;
            return;
        }
        // printboard(board);
        for(int i=0;i<n;i++){
            solveQueen(board,n,r+1,i);
        }
        board[r][c]=0;
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            solveQueen(board,n,0,i);
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.totalNQueens(4)<<endl;
    return 0;
}