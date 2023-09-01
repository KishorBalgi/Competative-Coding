// https://leetcode.com/problems/valid-parentheses/
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stk.push(s[i]);
            }else if(s[i]==')' && !stk.empty() && stk.top()=='('){
                stk.pop();
            }else if(s[i]==']' && !stk.empty() && stk.top()=='['){
                stk.pop();
            }else if(s[i]=='}' && !stk.empty() && stk.top()=='{'){
                stk.pop();
            }else{
                return false;
            }
        }
        return stk.empty();
    }
};

int main(){
    Solution s;
    string str="]";
    cout<<s.isValid(str)<<endl;
    return 0;
}