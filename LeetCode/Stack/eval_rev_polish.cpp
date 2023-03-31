// https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
    stack<int> val;
    int evalRPN(vector<string>& tokens) {
        int f,s;
        for(int i=0;i<tokens.size();i++){
            if(isdigit(tokens[i][0]) || isdigit(tokens[i][1])){
                val.push(stoi(tokens[i]));
            }else{
                s=val.top();
                val.pop();
                f=val.top();
                val.pop();
                val.push(eval(f,s,tokens[i]));
            }
        }
        return val.top();
    }
    int eval(int f,int s,string op){
        if(op=="+"){
            return f+s;
        }else if(op=="-"){
            return f-s;
        }else if(op=="*"){
            return f*s;
        }else{
            return f/s;
        }
    }
};

int main(){
    Solution s;
    vector<string> tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<s.evalRPN(tokens)<<endl;
    return 0;
}