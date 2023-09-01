// https://leetcode.com/problems/n-queens/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    void saveSoln(vector<vector<int>>& board,int n){
        vector<string> res;
        string s="";
        for(int i=0;i<n;i++){
            s="";
            for(int j=0;j<n;j++){
                if(board[i][j]){
                    s+="Q";
                }else{
                    s+=".";
                }
            }
            res.push_back(s);
        }
        result.push_back(res);
    }
    void printboard(vector<vector<int>>& board){
        int n=board.size();
        for(vector<int> v : board) {
            for(int s : v) cout<<s<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
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
            saveSoln(board,n);
            board[r][c]=0;
            return;
        }
        // printboard(board);
        for(int i=0;i<n;i++){
            solveQueen(board,n,r+1,i);
        }
        board[r][c]=0;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            solveQueen(board,n,0,i);
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<string>> res=sol.solveNQueens(4);
    for(vector<string> v : res) {
        for(string s : v) cout<<s<<endl;
        cout<<endl;
    }
    cout<<res.size()<<endl;
    return 0;
}