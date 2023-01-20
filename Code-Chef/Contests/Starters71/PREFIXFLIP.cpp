#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,ops=0;
        cin>>n>>k;
        string s,one;
        cin>>s;

        for(int i=0;i<k;i++){
            one.push_back('1');
        }

        for(int i=0;i<=n-k;i++){
            if(one.compare(s.substr(i,k))==0){
                cout<<ops<<endl;
                exit(0);
            }
        }
        int i=0;
        while(true){
            for(int j=i;j<i+k;j++){
                if(s[j]=='0'){
                    s[j]='1';
                }else{
                    s[j]='0';
                }
            }
            ops++;
            for(int i=0;i<n;i++){
                cout<<s[i]<<" ";
            }
            cout<<endl;
            if(one.compare(s.substr(i,k))==0){
                cout<<ops<<endl;
                exit(0);
            }else if(i>n-k){
                 i=0;
            }else{
                i++;
            }
        }
    }
    return 0;
}