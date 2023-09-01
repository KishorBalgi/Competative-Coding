// https://leetcode.com/problems/add-binary/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        pair<int,int> curSum;
        int i=a.length()-1,j=b.length()-1,c=0;
        string binsum="";

        while(i>=0 && j>=0){
            curSum=sum(a[i],b[j],c);
            binsum=to_string(curSum.first)+binsum;
            c=curSum.second;
            i--;
            j--;
        }

        while(i>=0){
            curSum=sum(a[i],'0',c);
            binsum=to_string(curSum.first)+binsum;
            c=curSum.second;
            i--;
        }

        while(j>=0){
            curSum=sum('0',b[j],c);
            binsum=to_string(curSum.first)+binsum;
            c=curSum.second;
            j--;
        }

        if(c==1){
            binsum="1"+binsum;
        }

        return binsum;
    }

    pair<int,int> sum(char a,char b,int c){
        int sum=int(a-'0')+int(b-'0')+c;
        cout<<sum<<endl;
        if(sum==0 ) return {0,0};
        else if(sum==1) return {1,0};
        else if(sum==2) return {0,1};
        else return {1,1};
    }
};

int main(){
    Solution sol;
    string a="1010",b="1011";
    cout<<int(a[0]-'0')+int(b[0]-'0')<<endl;
    cout<<sol.addBinary(a,b)<<endl;
    return 0;
}