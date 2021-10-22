#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	       int x,y,stp=0;
	       cin>>x>>y;
	       while(x!=y){
	              if(x<y && x!=y-1){
	                     x+=2;
	                     stp++;
	              }
	              else{
	                     x--;
	                     stp++;
	              }
	       }
	      cout<<stp<<"\n";
	}
	return 0;
}
