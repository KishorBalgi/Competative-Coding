// https://leetcode.com/problems/decode-string/

#include<iostream>
#include<stack>
// #include<cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }else if(c=='['){
                nums.push(num);
                chars.push(res);
                res="";
                num=0;
            }else if(c==']'){
                string cur=res;
                res=chars.top();
                for(int i=nums.top();i>0;i--){
                    res+=cur;
                }
                nums.pop();
                chars.pop();
            }else{
                res+=c;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s="3[a2[c]]";
    cout<<sol.decodeString(s)<<endl;
    return 0;
}