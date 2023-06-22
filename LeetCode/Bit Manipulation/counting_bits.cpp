// https://leetcode.com/problems/counting-bits/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // O(n logn):
    // vector<int> countBits(int n) {
    //     vector<int> res;

    //     for(int i=0;i<=n;i++){
    //         int sum=0;
    //         int num=i;
    //         while(num!=0){
    //             sum+=num%2;
    //             num=num/2;
    //         }
    //         res.push_back(sum);
    //     }
    //     return res;
    // }
    // O(n):
    // https://leetcode.com/problems/counting-bits/solutions/1808016/c-vectors-only-easy-to-understand-full-explanation/
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++){
            res[i]=res[i/2] + i%2;
        }
        return res;
    }
};

int main(){
    Solution sol;
    for(int i: sol.countBits(5)) cout<<i<<" ";
    return 0;
}