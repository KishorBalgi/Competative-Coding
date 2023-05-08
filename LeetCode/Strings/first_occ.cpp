// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        for(int i=0;i<haystack.length();i++){
            if(haystack[i]==needle[0]){
                if(needle.compare(haystack.substr(i,n))==0)return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    string haystack="sadbutsade",needle="sade";
    cout<<sol.strStr(haystack,needle)<<endl;
    return 0;
}