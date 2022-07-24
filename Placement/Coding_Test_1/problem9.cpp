// Write a program using functions and pointers to implement substrptr 
// (char s1[], char s2[]) with two arguments of character array type containing 
// source string (s1)and substring(s2). Function should return an address of a 
// substring in a string if present else a NULL pointer

#include<iostream>
#include<iomanip>
#include<cstring>
#include<string.h>
using namespace std;

char* subStrPtr(string s1,string s2){
    int n=s1.length(),m=s2.length();
    string substr;
    for(int i=0;i<=n-m;i++){
        substr=s1.substr(i,m);
        if(s2==substr){
            return &s1[i];
        }
    }
    return NULL;
}

int main(){
    string s1,s2;
    char* addr;
    cin>>s1>>s2;
    addr=subStrPtr(s1,s2);
    cout<<addr<<endl;
    return 0;

}