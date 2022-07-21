// Write a program to accept a number from the user and count the number of digits in the number.

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a,count=0;
    cout<<"Enter a number: ";
    cin>>a;
    if(a==0) count++;
    while (a!=0)
    {
        a=a/10;
        count++;
    }
    cout<<count<<endl;
}