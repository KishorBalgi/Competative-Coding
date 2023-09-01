// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> freqP,freqS;
        int n=p.length(),m=s.length(),j;
        vector<int> res;

        for(int i=0;i<n;i++){
            freqP[p[i]]++;
        }
        j=0;
        for(int i=0;i<m;i++){
            freqS[s[i]]++;

            if(i-j+1==n && freqP==freqS){
                res.push_back(j);
            }        

            if(i-j+1>=n){
                freqS[s[j]]--;
                if(freqS[s[j]]==0) freqS.erase(s[j]);
                j++;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s="acdcaeccde",p="c";
    vector<int> res;
    res=sol.findAnagrams(s,p);
    for(int i: res){
        cout<<i<<endl;
    }
    return 0;
}       
