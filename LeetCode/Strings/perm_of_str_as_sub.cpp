// https://leetcode.com/problems/permutation-in-string/

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.length(),m=s1.length(),l=0;
        map<char,int> freqS1,freqS2;
        bool res=false;
        for(char c : s1){
            freqS1[c]++;
        }

        for(int h=0;h<n;h++){
            freqS2[s2[h]]++;

            if(h-l+1==m && freqS1==freqS2){
                res=true;
                break;
            }

            if(h-l+1>=m){
                freqS2[s2[l]]--;
                if(freqS2[s2[l]]==0) freqS2.erase(s2[l]);
                l++;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    string s1="ab",s2="eidbaooo";
    cout<<(sol.checkInclusion(s1,s2)?"True":"False")<<endl;
    return 0;
}