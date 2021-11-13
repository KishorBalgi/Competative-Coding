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
	    int a,b,cnt=0,i;
		cin>>a>>b;
		for(i=a;i<=b;i++){
			if(i%10==4 ||i%10==7 ||i%10==9) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
