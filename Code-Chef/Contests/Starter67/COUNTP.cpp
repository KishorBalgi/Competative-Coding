#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e=0,o=0,a;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a%2==0){
                e+=a;
            }else{
                o+=a;
            }
        }
        if(abs(e-o)%2==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}

