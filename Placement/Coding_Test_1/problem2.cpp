// Write a program to accept a four digit number from the user and display its denomination.

#include<iostream>
#include<cmath>
using namespace std;

int length(int n){
    int count =0;
    while (n!=0)
    {
        n=n/10;
        count++;
    }
    return count;
}

int reverse(int n){
    int rev=0,rem=0;
    while (n!=0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    return rev;
}

int main(){
    int a,rev,count,rem,power;
    cout<<"Enter a number: ";
    cin>>a;
    count=length(a);
    rev=reverse(a);
    for(int i=count-1;i>=0;i--){
        rem=rev%10;
        power=pow(10,i);
        cout<<rem<<"*"<<power<<" = "<<rem*power<<endl;
        rev=rev/10;
    }
    return 0;
}