// https://leetcode.com/problems/reverse-string/?envType=study-plan&id=algorithm-i

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void reverseString(vector<char>& s) {
        int b=0,n=s.size(),e=n-1;
        char temp;
        while(b<e){
            temp=s[b];
            s[b]=s[e];
            s[e]=temp;
            b++;e--;
        }
        for(char c:s){
            cout<<c<<" ";
        }
    }
};

int main(){
    Solution s;
    vector<char> str={'h','e','l','l','o'};
    s.reverseString(str);
    return 0;
}