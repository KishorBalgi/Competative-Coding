#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

void checkPass(char pass[],int *a,int *d,int *s){
    for(int i=0;i<strlen(pass) && (*a==0 || *d==0 ||*s==0);i++){
        if(isalpha(pass[i]))
            *a=1;
        if(isdigit(pass[i]))
            *d=1;
        if(!isalpha(pass[i]) && !isdigit(pass[i])){
            *s=1;
        }
    }
}

int main(){
    char s[]="";
    int alpha=0,digit=0,spch=0;
    cin>>s;
    checkPass(s,&alpha,&digit,&spch);
    if(alpha==1 && digit==1 && spch==1){
        cout<<"Strong Password"<<endl;
    }
    else if(alpha==1 && digit==1 && spch==0){
        cout<<"Moderate Password"<<endl;
    }
    else if(alpha==1 && digit==0 && spch==0){
        cout<<"Weak Password"<<endl;
    }
    else{
        cout<<"Invalid Password"<<endl;
    }
    return 0;
}