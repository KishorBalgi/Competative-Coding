// https://leetcode.com/problems/valid-sudoku/

#include<iostream>
#include<vector>    
#include<set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> temp;
        int count=0;
        // Row Check:
        for(int i=0;i<9;i++){
            count=0;
            temp={};
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    temp.insert(board[i][j]);
                    count++;
                }
            }
            if(temp.size()!=count)
                return false;
        }
        // Column Check:
        for(int i=0;i<9;i++){
            count=0;
            temp={};
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    temp.insert(board[j][i]);
                    count++;
                }
            }
            // cout<<temp.size()<<" : "<<count<<endl;
            if(temp.size()!=count)
                return false;
        }
        // Individual 3X3 block check:
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                temp={};
                count=0;
                for(int i=3*m;i<3*m+3;i++){
                    for(int j=3*n;j<3*n+3;j++){
                        if(board[i][j]!='.'){
                            temp.insert(board[i][j]);
                            count++;
                        }
                    }
                    if(temp.size()!=count){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board;
    board={{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};
    cout<<s.isValidSudoku(board)<<endl;
    return 0;
}
