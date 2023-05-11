#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),top=0,bottom=m-1,left=0,right=n-1,dir=0;
        vector<int> res;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
                dir++;
            }else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                dir++;
            }else if(dir==2){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir++;
            }else{
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
                dir=0;
            }
        
            
            
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> res;
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    res=s.spiralOrder(matrix);
    for(int i: res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}