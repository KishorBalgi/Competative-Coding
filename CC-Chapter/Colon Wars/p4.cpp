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
	    int n,s=0,flag=1,f1=1,tmp=-1;
        cin>>n;
        int g[n],c[n];

        for(int i=0;i<n;i++){
            cin>>g[i];
             int j=g[i];
            if(j==2) j++;
            int p=pow(2,j-1);
            if(p%j!=1) {
                flag=0;}
        }
        // for(int i=0;i<n;i++){
        //     int j=g[i];
        //     if(j==2) j++;
        //     int p=pow(2,j-1);
        //     if(p%j!=1) {
        //         flag=0;
        //         break;}
        // }

        if(flag==1){
            cout<<"Do not distribute"<<endl;
        }
        else{
            cout<<"Distribute"<<endl;
            for(int k=2;k<=n;k++){
                flag=1;
                for(int j=0;j<n;j++){
                    int l=g[j]%k;
                    if(l==0 && l!=tmp){
                        tmp=0;
                    }
                    else if(l==1 && l!=tmp){
                        tmp=1;
                    }else{
                        flag=0;
                        break;
                    }
                    
                
                // for(int j=0;j<n;j++){
                //     if(g[j]%k==0){
                //         c[j]=1;
                //     }else{
                //         c[j]=0;
                //     }
                // }
                
                // for(int i=0;i<n-1;i++){
                //     if(c[i]==c[i+1]){
                //         flag=0;
                //         break;
                //     }
                // }
                }
                if(flag){
                    cout<<k<<endl;
                    f1=0;
                }
                

            }
            if(f1){
                    cout<< "Coloring is not possible"<<endl;
                }
        }
        
	}
	return 0;
}
