// https://leetcode.com/problems/pascals-triangle/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> row(numRows+1,1);
        for(int i=0;i<=numRows;i++){
            vector<int> temp;
            for(int j=i-1;j>0;j--){
                row[j]=row[j]+row[j-1];
            }
        }
        return row;
    }
};

int main(){
    Solution sol;
    for(int v: sol.getRow(3)){
        cout<<v<<" ";
    }
    return 0;
}