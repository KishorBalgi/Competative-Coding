// https://leetcode.com/problems/pascals-triangle/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(i>0 && j-1>=0 && j<i){
                    temp.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
                }else{
                    temp.push_back(1);
                }
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};

int main(){
    Solution sol;
    for(vector<int> v: sol.generate(5)){
        for(int i:v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}