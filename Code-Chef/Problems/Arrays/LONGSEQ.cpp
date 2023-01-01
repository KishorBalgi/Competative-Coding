#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a=-1,b=-1;
        string n;
        cin>>n;
        for(int i=0;i<n.size();i++){
            if (n[i]=='0')
                a++;
            else
                b++;
        }
        if(a==0 || b==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;

        }

    }
}

