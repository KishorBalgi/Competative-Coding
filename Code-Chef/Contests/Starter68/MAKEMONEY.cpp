#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,c,count=0,max=0,ci=0,res=0,cc=0,nc=0;
        cin>>n>>x>>c;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>=x){
                cc+=a[i];
            }
            else{
                count++;
            }
            max+=a[i];
        }
        ci=n-count;
        for(int i=count;i>=0;i--){
            res=cc+i*x-i*c;
            cout<<res<<endl;
            if(res>max){
                max=res;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}