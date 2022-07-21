// Write a program to accept a five digit number from the user, increment each digit by one and display the number (digit 9 gets incremented to 0).

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

int main(){
    int a,b=0,count,rem;
    cout<<"Enter a number: ";
    cin>>a;
    count=length(a);
    for(int i=0;i<count && a!=0;i++){
        rem=a%10;
        if(rem==9) rem=0;
        else rem++;
        b+=rem*pow(10,i);
        a=a/10;
    }
    cout<<b<<endl;
    return 0;
}