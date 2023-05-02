// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> pos;
        int maxLength=0;
        int i=0,j=0,n=s.length();
        int len=0;
        while(i<n && j<n){
                if(pos.count(s[j])==0){
                    pos.insert({s[j],j});
                    len=j-i+1;
                    maxLength=max(maxLength,len);
                }else{
                    int newi=pos[s[j]]+1;
                    for(int k=i;k<newi;k++){
                        pos.erase(s[k]);
                    }
                    i=newi;
                    len=j-newi+1;
                    pos[s[j]]=j;
                    maxLength=max(maxLength,len);
                }
                j++;
        }
        return maxLength;
    }
};

int main(){
    Solution s;
    string str="abba";
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}