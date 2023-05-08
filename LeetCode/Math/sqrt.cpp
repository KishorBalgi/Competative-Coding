// https://leetcode.com/problems/sqrtx/ 

#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l=1,h=x,m=0;
        while(l<=h){
            m=l+(h-l)/2;
            if(m==x/m) return m;
            else if(m>x/m) h=m-1;
            else l=m+1;
        }
        return h;
    }
};

int main(){
    Solution sol;
    cout<<sol.mySqrt(19)<<endl;
    return 0;
}