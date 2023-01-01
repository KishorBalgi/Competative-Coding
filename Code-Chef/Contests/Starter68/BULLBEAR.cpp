#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int b,s;
        cin>>b>>s;
        if(b==s)
            cout<<"NEUTRAL"<<'\n';
        else if(b<s)
            cout<<"PROFIT"<<'\n';
        else
            cout<<"LOSS"<<'\n';

    }
}