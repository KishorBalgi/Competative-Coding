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
	    string str;
        char c;
        cin>>str;
        int n=str.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                   int a=int(str[j]);
                   int b=int(str[j++]);
                if(a>b){
                    c=char(str[j]);
                    str[j]=str[j++];
                    str[j++]=c;
                }
            }
        }
        cout<<str<<endl;
	}
	return 0;
}
