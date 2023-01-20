#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int b,s;
        cin>>b>>s;
        if((s-b)%2==0)
            cout<<(s+b)/2<<'\n';
        else
            cout<<-1<<'\n';

    }
    return 0;
}