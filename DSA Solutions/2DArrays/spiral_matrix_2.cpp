// https://leetcode.com/problems/spiral-matrix-ii/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int top=0,bottom=n-1,left=0,right=n-1,dir=0,ele=1;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    res[top][i]=ele++;
                }
                top++;
                dir++;
            }else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    res[i][right]=ele++;
                }
                right--;
                dir++;
            }else if(dir==2){
                for(int i=right;i>=left;i--){
                    res[bottom][i]=ele++;
                }
                bottom--;
                dir++;
            }else{
                for(int i=bottom;i>=top;i--){
                    res[i][left]=ele++;
                }
                left++;
                dir=0;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> res=sol.generateMatrix(5);
    for(vector<int> r:res){
        for(int ele: r){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}