#include <iostream>
#include<cstdlib>
using namespace std;

int min(int a,int b){
    return a<b?a:b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c,d,mina=0,mins,mine;
        cin>>n>>a>>b>>c>>d;
        mina=abs(a-c)+abs(b-d);
        mins=min(min(abs(b-0),abs(b-n)+1),min(abs(a-0),abs(a-n)+1));
        mine=min(min(abs(d-0),abs(d-n)+1),min(abs(c-0),abs(c-n)+1)); 
        cout<<min(mina,mins+mine)<<endl;

    }

}

