// https://leetcode.com/problems/plus-one/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1,sum=0;
        for(int i=digits.size()-1;i>=0;i--){
            sum=digits[i]+c;
            digits[i]=sum%10;
            c=sum/10;
        }
        if(c!=0) digits.insert(digits.begin(),c);
        return digits;
    }
};

int main(){
    Solution sol;
    vector<int> digits={9};
    for(int i :  sol.plusOne(digits)) cout<<i<<" "; cout<<endl;
    return 0;
}