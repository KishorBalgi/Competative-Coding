// https://leetcode.com/problems/length-of-last-word/

#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length(),e=n-1,b=0;
        // move end to position where char is not space:
        while(e>=0 && s[e]==' '){
            e--;
        }
        b=e;
        // find the length:
        while(b>=0 && s[b]!=' ' ){
            b--;
        }
        return e-b;
    }
};

int main(){
    Solution sol;
    string s="moon  ";
    cout<<sol.lengthOfLastWord(s)<<endl;
    return 0;
}