// https://leetcode.com/problems/palindromic-substrings/
#include<iostream>

using namespace std;

class Solution {
public:
    int count=0;
    int countSubstrings(string s) {
        int len=s.length();
        int l,r;
        for(int i=0;i<len;i++){
            // Odd length:
            findSubLargestPalindrome(s,i,i);
            // Even length:
            findSubLargestPalindrome(s,i,i+1);
        }
        return count;
    }
    void findSubLargestPalindrome(string s,int l,int r){
        int len=s.length();
        while(l>=0 && r<len && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
    }
};

int main(){
    Solution s;
    cout<<s.countSubstrings("babbca")<<endl;
    return 0;
}