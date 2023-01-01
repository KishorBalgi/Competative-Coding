#include <bits/stdc++.h>
using namespace std;

#define tc ll t sc cin >> t sc while(t--)
#define sc ;
#define ll long long
#define syncf ios_base::sync_with_stdio(false);
#define cintie cin.tie(NULL);
#define couttie cout.tie(NULL);
int findNear(string s,int n,int pos){
    int l,r,i,min;
    ll int len;
    if(s[i]==1) return 0;
    for(i=pos+1;i<n;i++){
        if(s[i]==1) {
            r=i;
            break;}
    }
    for(i=pos-1;i>=0;i--){
        if(s[i]==1) {
            l=i;
            break;}
    }
    min=(l<r)?l:r;
    return abs(pos-min);
}
int main() {
    syncf;
	cintie;
	couttie;
	tc {
	    ll int n,k,i,tot=0;
        string s;
        cin>>n>>k;
        cin>>s;
        for(i=0;i<n;i++){
            tot+=k+findNear(s,n,i);
        }
        cout<<tot<<"\n";
	}
	return 0;
}
