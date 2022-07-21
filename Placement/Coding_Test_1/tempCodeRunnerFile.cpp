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
        cout<<rem<<endl;
        b+=rem*pow(10,i);
        cout<<"pow"<<pow(10,i)<<endl;
        cout<<"b"<<b<<endl;
        a=a/10;
    }
    cout<<b<<endl;
    return 0;
}