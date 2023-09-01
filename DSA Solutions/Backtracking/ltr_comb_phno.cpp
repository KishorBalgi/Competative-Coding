// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    map<char,vector<char>> ntc;
    vector<string> res;
    Solution(){
        ntc['2']={'a','b','c'};
        ntc['3']={'d','e','f'};
        ntc['4']={'g','h','i'};
        ntc['5']={'j','k','l'};
        ntc['6']={'m','n','o'};
        ntc['7']={'p','q','r','s'};
        ntc['8']={'t','u','v'};
        ntc['9']={'w','x','y','z'};
    }
    void backtracking(string s,string temp,int i){
        if(i==s.length() && i!=0){
            res.push_back(temp);
            return;
        }
        vector<char> chars=ntc[s[i]];
        for(char c: chars){
            backtracking(s,temp+c,i+1);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        string temp="";
        backtracking(digits,temp,0);
        return res;
    }
};

int main(){
    Solution s;
    string str="";
    vector<string> res;
    res=s.letterCombinations(str);
    for(string a:res){
        cout<<a<<" ";
    }
    return 0;
}