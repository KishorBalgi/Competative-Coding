#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	       int a[5],i,ind=0,eng=0;
	       for(i=0;i<5;i++){
	              cin>>a[i];
	              if(a[i]!=0)
	                     if(a[i]==1) ind++;
	                     else eng++;
	       }
	       cout<<(ind==eng?"DRAW":ind>eng?"INDIA":"ENGLAND")<<endl;
	}
	return 0;
}
