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
	ll int n;
	int i,j,k,cnt=0,min,flag=0;
	cin>>n;
	ll int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n-1;i++){
		for(j=i+2;j<n;j++){
			min=a[i]<a[j]?a[i]:a[j];
			for(k=i+1;k<j;k++){
					if(a[k]>min) {flag=1;break;}
			}	
				cnt+=flag?0:1;
		}
	}
	cout<<cnt+n-1<<"\n";
	return 0;
}
