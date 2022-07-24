// Given the list of N names, print it based on the alphabetical order of the first letter. If the first
// letter of the two names is the same, print it in the order in the array.
// Eg,
// If the Names are Alice, Noah, Bob. Print it as Alice, Bob, Noah.
// If the Names are Alice, Bob, Noah, Adam. Print it as Alice, Adam, Bob, Noah
// If the Names are Bob, Alice, Adam, Ava. Print it as Alice, Adam, Ava, Bob.

#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

int main(){
    int n;
    cin>>n;
    string temp;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            if(s[j][0]>s[j+1][0]){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
}