// https://leetcode.com/problems/prime-palindrome/
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int n){
        string s=to_string(n);
        int len=s.length(),i,j;
        if(s.length()%2==0){
            i=len/2-1;
            j=i+1;
            while(i>=0 && j<len){
                if(s[i]!=s[j]) return false;
                i--;j++;
            }
        }else{
            i=len/2;
            j=i;
            while(i>=0 && j<len){
                if(s[i]!=s[j]) return false;
                i--;j++;
            }
        }
        return true;
    }
    bool isPrime(int n){
        if(n<2) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        while(true){
            if(isPrime(n)){
                if(isPalindrome(n)) return n;
            }
            n++;
        }
    }
};

int main(){
    Solution sol;
    cout<<sol.primePalindrome(1);
    return 0;
}