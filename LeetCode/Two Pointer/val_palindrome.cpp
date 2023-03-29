// https://leetcode.com/problems/valid-palindrome/
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j;
        while(i<s.length()){
            if(!isalnum(s[i])){
                s.erase(i,1);
            }else{
                i++;
            }
        }
        transform(s.begin(),s.end(),s.begin(),::tolower);
        i=0;j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j])
                return false;
                i++;j--;
        }
        return true;
    }
};

int main(){
    Solution s;
    string str="race a car";
    cout<<s.isPalindrome(str)<<endl;
    return 0;
}