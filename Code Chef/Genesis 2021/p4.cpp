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
	    int n,i,cnt=0;
		cin>>n;
		int a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
			if(a[i]%2==0) cnt++;
		} 
		cout<<cnt<<"\n";
	}
	return 0;
}
