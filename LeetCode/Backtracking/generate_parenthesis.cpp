// https://leetcode.com/problems/generate-parentheses/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    void backtracing(string temp,int max,int open,int count){
        if(count==max && open==0){
            res.push_back(temp);
            return;
        }
        if(count<max){
            backtracing(temp+"(",max,open+1,count+1);
        }
        if(open!=0){
            backtracing(temp+")",max,open-1,count);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        backtracing("(",n,1,1);
        return res;
    }
};

int main(){
    Solution s;
    vector<string> res;
    res=s.generateParenthesis(3);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}