// https://leetcode.com/problems/container-with-most-water/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int maxArea(vector<int> &height){
            int max=0,area=0,i=0,j=height.size()-1;
            while(i<j){
                if(height[i]<=height[j]){
                    area=height[i]*(j-i);
                    i++;
                }else{
                    area=height[j]*(j-i);
                    j--;
                }
                max=area>max?area:max;
            }
            return max;
        }
};

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    Solution obj;
    cout<<obj.maxArea(height)<<endl;
    return 0;
}