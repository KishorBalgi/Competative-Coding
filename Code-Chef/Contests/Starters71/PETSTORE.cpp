#include<iostream>
#include<map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,count=0;
        cin>>n;
        int a[n];
        std:map<int,int> animal_count;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i:a){
            ++animal_count[i];
        }
        for(const auto &item:animal_count){
            if(item.second%2!=0){
                count=-1;
            }
        }
        if(count==-1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

    }
    return 0;
}