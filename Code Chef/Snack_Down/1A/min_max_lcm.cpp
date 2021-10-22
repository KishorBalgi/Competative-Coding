#include <bits/stdc++.h>
using namespace std;
#define tc ll t sc cin >> t sc while (t--)
#define sc ;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	tc{
        ll x,k;
	
	    cin>>x>>k;
	    
	    cout<<2*x<<" "<<x*k*(x*k-1)<<"\n";
	}
	return 0;
}
