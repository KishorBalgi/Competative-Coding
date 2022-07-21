// Write a program to generate following patterns
// 1
// 1 2 1
// 1 2 3 2 1
// 1 2 3 4 3 2 1
// 1 2 3 4 5 4 3 2 1


#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int j=i-1;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }
}