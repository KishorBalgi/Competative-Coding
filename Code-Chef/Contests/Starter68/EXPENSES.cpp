#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,e,i,a;
        cin>>n>>x;
        a=pow(2,x);
        e=(a/2)*(pow(.5,n)-1)/(-0.5);
        cout<<a-e<<endl;
    }
    return 0;
}