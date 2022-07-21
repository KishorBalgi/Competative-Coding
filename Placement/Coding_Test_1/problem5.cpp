// Write a program to accept the lower bound number and the upper bound number from the user and print the prime numbers between them.

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    int l,u,a;
    cout<<"Enter the lower bound: ";
    cin>>l;
    cout<<"Enter the upper bound: ";
    cin>>u;
    for(int i=l;i<=u;i++){
        if(i==2) a=1;
        else a=2;
        int power=pow(a,i-1);
        if(power%i==1)
            cout<< i<<" ";
    }
    return 0;
}