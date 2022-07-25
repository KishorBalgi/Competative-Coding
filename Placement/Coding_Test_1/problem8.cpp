#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

int main(){
    int flag=1,i=0,j=1,l=0;
    string s;
    cin>>s;
    while(j<s.length()){
        if(s[i]==s[j]){
            j++;
        }
        else if(j-i>=3){
            s.erase(i,j-i);
            i=0;
            j=1;
        }
        else{
            i++;
            j++;
        }
        l++;
    }
    cout<<s<<endl;
    cout<<l<<endl;
}