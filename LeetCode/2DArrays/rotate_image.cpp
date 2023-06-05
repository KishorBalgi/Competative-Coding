// https://leetcode.com/problems/rotate-image/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    // More optimal approach: https://leetcode.com/problems/rotate-image/solutions/3440564/animation-understand-in-30-seconds/
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=n-1,temp=0,temp2=0,a=0,b=0;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<m-i;j++){
                // r top -> c left:
                a=j;
                b=m-i;
                cout<<a<<" "<<b<<endl;
                temp=matrix[a][b];
                matrix[a][b]=matrix[i][j];

                // c left <- r bottom:
                a=m-i;
                b=m-j;
                cout<<a<<" "<<b<<endl;
                temp2=matrix[a][b];
                matrix[a][b]=temp;

                // r bottom <- c right:
                a=b;
                b=i;
                cout<<a<<" "<<b<<endl;
                temp=matrix[a][b];
                matrix[a][b]=temp2;

                // c right -> r top:
                matrix[i][j]=temp;
                cout<<endl;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix={
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    sol.rotate(matrix);
    for(vector<int> v: matrix){
        for(int i:v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}