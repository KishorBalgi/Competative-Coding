#include <bits/stdc++.h>
using namespace std;


int main() {
    int i,j,x,a,b,temp,n;
    cin>>i>>j>>x;
    n=0;
    for(i;i<=j;i++){
        a=temp=i;
        b=0;
        while(temp!=0){
            b=b*10+temp%10;
            temp=temp/10;
        }
        if((a-b)%x==0){
            n++;
        }
    }
    cout<<n;
	return 0;
}
