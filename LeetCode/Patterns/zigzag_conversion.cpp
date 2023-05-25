// https://leetcode.com/problems/zigzag-conversion/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> grid(numRows);
        int n=s.length(),pos=0,i=0;
        while(pos!=n){
            while(i!=numRows && pos!=n){
                grid[i++].push_back(s[pos++]);
            }
            i-=2;
            while(i>0 && pos!=n){
                grid[i--].push_back(s[pos++]);
            }
        }
        string res="";
        for(vector<char> v: grid){
            string str(v.begin(),v.end());
            res+=str;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.convert("PAYPALISHIRING",3);
    return 0;
}