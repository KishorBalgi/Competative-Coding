#include <bits/stdc++.h>
using namespace std;

#define tc ll t sc cin >> t sc while(t--)
#define sc ;
#define ll long long
#define syncf ios_base::sync_with_stdio(false);
#define cintie cin.tie(NULL);
#define couttie cout.tie(NULL);
int main() {
       syncf;
	cintie;
	couttie;
	tc {
	    int a,n,b,temp;
        cin>>a;
        b=n=0;
        temp=a;
        while(temp!=0){
            b=b*10+temp%10;
            temp=temp/10;
            n++;
        }
        if(a==b){
            cout<<pow(n,n)<<endl;
        }
        else{
            cout<<(n*n)<<endl;
        }

	}
	return 0;
}
