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
	    int n,k,i,pos=0;
		cin>>n>>k;
		int a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==k) pos=i+1;
		}
		if(pos!=0){
			cout<<pos<<"\n";
		}
		else{
			cout<<"not found"<<"\n";
		}
	}
	return 0;
}
