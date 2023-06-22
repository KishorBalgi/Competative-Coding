// https://leetcode.com/problems/reverse-bits/

#include<iostream>
using namespace std;

class Solution {
    public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int pos=0;
        while(n>0){
            res+= (n % 2) << (31-pos);
            n>>=1;
            pos++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    uint32_t n=5;
    cout<<sol.reverseBits(n)<<endl;
    return 0;
}