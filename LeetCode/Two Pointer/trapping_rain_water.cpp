// https://leetcode.com/problems/trapping-rain-water/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
int trap(vector<int>& height) {
        int j=1,k=1,n=height.size(),preH=height[0],postH=k,units=0;
        if(height.size()<3) return 0;
        while(j!=n-1){
            if(j>=k){
                k=findNextHighest(j,height);
                postH=height[k];
                if(k==j){
                    if(height[j]>preH){
                        preH=height[j];
                    }
                    j++;
                    continue;
                }
            }
            if(preH>height[j] && postH>height[j]){
                units+=(smallestOf(preH,postH)-height[j]);
            }
            if(height[j]>preH){
                preH=height[j];
            }
            j++;
        }
        return units;
    }
    int findNextHighest(int j,vector<int>& height){
        int highest=j;
        for(int i=j+1;i<height.size();i++){
            if(height[i]>height[highest]){
                highest=i;
            }
        }
        return highest;
    }
    int smallestOf(int i,int j){
        return i<j?i:j;
    }
};

int main(){
    Solution s;
    vector<int> height={5,5,1,7,1,1,5,2,7,6};
    cout<<s.trap(height)<<endl;
    return 0;
}