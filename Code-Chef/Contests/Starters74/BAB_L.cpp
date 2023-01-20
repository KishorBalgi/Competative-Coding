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
	    int n,neg=-1,pos=-1;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        for(int i=0;i<n-1;i++){
            if(a[i]<0 && a[i+1]>0){
                neg=a[i];
                pos=a[i+1];
            }
        }
        while(abs(neg) != pos){
            if(abs(neg)>pos){
                neg=-pos;
                cout<<neg;
            }else{
                pos=abs(neg);
            }
            break;
        }
        cout<<neg<<" "<<pos;

	}
	return 0;
}
