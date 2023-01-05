#include<iostream>
#include<map>
using namespace std;

class Solution{
    public:
        int romanToInt(string s){
            map<char,int> mp;
            mp['I']=1;
            mp['V']=5;
            mp['X']=10;
            mp['L']=50;
            mp['C']=100;
            mp['D']=500;
            mp['M']=1000;

            int ans=0;
            for(int i=s.length()-1;i>=0;i--){
                if(i==s.length()-1){
                    ans+=mp.at(s[i]);
                }else if(priority(s[i])<priority(s[i+1])){
                    ans-=mp.at(s[i]);
                }else{
                    ans+=mp.at(s[i]);
                }
            }
            return ans;
        }

        int priority(char s){
            if(s=='M')
                return 7;
            else if(s=='D')
                return 6;
            else if(s=='C')
                return 5;
            else if(s=='L')
                return 4;
            else if(s=='X')
                return 3;
            else if(s=='V')
                return 2;
            else 
                return 1;
        }
};

int main(){
    string s="MCMXCIV";
    Solution a;
    cout<<a.romanToInt(s)<<endl;
}