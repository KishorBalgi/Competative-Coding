#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	       int a[3],l=0;
	       for(int i=0;i<3;i++){
	              cin>>a[i];
	              if(a[i]==7)
	                     l++;
	       }     
	       cout<<(l?"YES":"NO")<<endl;
	}
	return 0;
}
