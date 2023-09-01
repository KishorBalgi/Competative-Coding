// https://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void fillBoard(vector<vector<char>>& board){
        int m=board.size(),n=board[0].size();
        int top=0,bottom=m-1,left=0,right=n-1;
        char token='X';

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                board[top][i]=token;
            }
            top++;

            for(int i=top;i<=bottom;i++){
                board[i][right]=token;
            }
            right--;

            for(int i=right;i>=left;i--){
                board[bottom][i]=token;
            }
            bottom--;

            for(int i=bottom;i>=top;i--){
                board[i][left]=token;
            }
            left++;

            token=token=='X'?'O':'X';
        }
    }
};

int main(){
    Solution sol;
    int m=6,n=7;
    vector<vector<char>> board(m,vector<char>(n,'#'));

    sol.fillBoard(board);

    for(auto row: board){
        for(char item: row){
            cout<<item<<" ";
        }
        cout<<endl;
    }
    return 0;
}