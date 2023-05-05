// https://leetcode.com/problems/longest-repeating-character-replacement/

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int length=0,maxfreq=0;
        map<char,int> items;
        int n=s.length();
        int i=0,j=0;
        while(j<n){
            items[s[j]]++;
            maxfreq=max(maxfreq,items[s[j]]);
            if((j-i+1)-maxfreq>k){
                items[s[i]]--;
                i++;
            }
            length=max(length,j-i+1);
            j++;
        }
        return length;
    }
};

int main(){
    Solution s;
    string str = "AABABBA";
    int k=1;
    cout<<s.characterReplacement(str,k)<<endl;
    return 0;
}