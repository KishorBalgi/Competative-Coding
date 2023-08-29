// 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int N,M;
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || j<0 || i>=M || j>=N || board[i][j] !='O') return;

        board[i][j]='$';

        dfs(board,i,j-1);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i+1,j);
    }
    void solve(vector<vector<char>>& board) {
        M=board.size(),N=board[0].size();

        for(int i=0;i<M;i++){
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][N-1]=='O')
                dfs(board,i,N-1);
        }

        for(int i=0;i<N;i++){
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[M-1][i]=='O')
                dfs(board,M-1,i);
        }

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='$')
                    board[i][j]='O';
            }
        }
    }
};

int main(){
    Solution sol;

    return 0;
}