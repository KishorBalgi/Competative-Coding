// https://leetcode.com/problems/decode-ways/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.length(),dp1=0,dp2=0;
        if(n<2) return 1;
        if(s[n-1]-'0'>0){
            dp2=1;
        }
        if(s[n-2]!='0'){
            int num=stoi(s.substr(n-2,2));
            if(num<27) dp1=dp2+1;
            else dp1=dp2;
        }
        for(int i=n-3;i>=0;i--){
            int temp=0;
            if(s[i]!='0'){
                temp=dp1;
                int num=stoi(s.substr(i,2));
                if(num<27) temp+=dp2;
            }
            dp2=dp1;
            dp1=temp;
        }
        return dp1;
    }
};

int main(){
    Solution sol;
    cout<<sol.numDecodings("10")<<endl;
    return 0;
}