// https://leetcode.com/problems/longest-palindromic-substring/
#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int len=s.length();
        int l,r;
        for(int i=0;i<len;i++){
            // Odd length:
            findSubLargestPalindrome(s,res,i,i);
            // Even length:
            findSubLargestPalindrome(s,res,i,i+1);
        }
        return res;
    }
    void findSubLargestPalindrome(string s, string & res,int l,int r){
        int len=s.length();
        while(l>=0 && r<len && s[l]==s[r]){
            if(r-l+1 > res.length()){
                res=s.substr(l,r-l+1);
            }
            l--;
            r++;
        }
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("babbca")<<endl;
    return 0;
}