// https://leetcode.com/problems/word-search/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m,n;
    string w;
    vector<vector<int>> v;
    vector<vector<char>> b;
    bool backtracking(int i,int j,int pos){
        if(pos==w.length()) return true;

        if(i<0 || i==b.size() || j<0 || j==b[0].size() || v[i][j] || w.at(pos)!=b[i][j]) return false;

        v[i][j]=1;
        pos++;
        bool res= backtracking(i,j+1,pos) ||
        backtracking(i,j-1,pos) ||
        backtracking(i+1,j,pos) ||
        backtracking(i-1,j,pos);
        v[i][j]=0;
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        vector<vector<int>> visited(m, vector<int> (n,0));
        w=word;
        v=visited;
        b=board;
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                if(backtracking(a,b,0)) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> broad={
        {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}
    };
    string word = "ABCCED";
    cout<<sol.exist(broad,word);

    return 0;
}