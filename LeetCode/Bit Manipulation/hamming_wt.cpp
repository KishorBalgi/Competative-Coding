// https://leetcode.com/problems/number-of-1-bits/

#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n!=0){
            res+=n & 1;
            n=n>>1;
        }
        return res;
    }
};

int main(){
    Solution sol;
    uint32_t n=11;
    // sol.hammingWeight(n);
    cout<<sol.hammingWeight(n)<<endl;
    return 0;
}