// https://leetcode.com/problems/reverse-words-in-a-string-iii/?envType=study-plan&id=algorithm-i

#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i=0,n=s.length(),j=0,k=0;
        char temp;
        while(j<n){
            // "Let's take"
            while(s[j+1]!=' ' && j+1<n){
                j++;
            }
            cout<<j<<endl;
            k=j;
            while(i<k){
                temp=s[i];
                s[i]=s[k];
                s[k]=temp;
                i++;k--;
            }
            j=j+2;
            i=j;
        }
        return s;
    }
};

int main(){
    Solution s;
    string str="Let's take";
    cout<<s.reverseWords(str)<<endl;
    return 0;
}