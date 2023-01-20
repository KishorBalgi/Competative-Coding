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
	    int n,cMax;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cMax=0;
        for(int i=1;i<n;i++){
            if(a[i]==a[cMax]){
                if(b[i]>b[cMax]){
                    cMax=i;
                }
            }else if(a[i]>a[cMax]){
                cMax=i;
            }
        }
        cout<<cMax+1<<endl;
    
	}
	return 0;
}