// https://leetcode.com/problems/restore-ip-addresses/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    void backtracking(string s,string temp,int i,int curVal,int count){
        int newCurr;
        if(curVal>255) return;
        if(count==0 && i==s.length()){
            res.push_back(temp);
            return;
        }
        else if(i==s.length()) return;
        if(curVal!=-1){
            backtracking(s,temp+'.',i,-1,count-1);
        }
        if(curVal==-1){
            newCurr=s[i]-'0';
        }else{
            newCurr=(curVal*10)+(s[i]-'0');
        }
        if(temp.length()==1 && temp[0]=='0') return;
        if(temp.length()>1 && temp[temp.length()-1]=='0' && temp[temp.length()-2]=='.') return;
        backtracking(s,temp+s[i],i+1,newCurr,count);
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        string temp="";
        backtracking(s,temp,0,-1,3);
        return res;
    }
};

int main(){
    Solution s;
    // string str="25525511135";
    string str="010010";
    vector<string> res;
    res=s.restoreIpAddresses(str);
    for(auto ip:res){
        cout<<ip<<endl;
    }
    return 0;
}