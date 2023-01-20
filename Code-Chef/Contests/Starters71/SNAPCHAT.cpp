#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,max=0,cur_max=0;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        for(int i=0;i<n;i++){
            if(a[i]!=0 && b[i]!=0){
                max++;
                cur_max=cur_max>max?cur_max:max;
            }
            else
                max=0;   
        }
        cout<<cur_max<<endl;
    }
    return 0;
}