// Program to Sort first half in ascending order and second half in descending order in an array

#include<iostream>

using namespace std;

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n/2-1;i++){
        for(int j=0;j<n/2-i-1;j++){
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
    for(int i=n/2,k=0;i<n-1;i++,k++){
        for(int j=n/2;j<n-k-1;j++){
            if(a[j]<a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}