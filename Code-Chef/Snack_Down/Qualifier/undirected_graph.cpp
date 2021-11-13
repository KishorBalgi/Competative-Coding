#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
    cin>>t;
    while(t--){
        int n,m,i,j,val,max,min;
        cin>>n>>m;
        int e[m][2],d[n]={0};
        for(i=0;i<m;i++)
            for(j=0;j<2;j++)
                cin>>e[i][j];

        // for(i=0;i<n;i++){
        //     c[i]=i+1;
        // }
        
        for(i=0;i<m;i++){
            if(e[i][0]>e[i][1]){
                d[(e[i][0])-1]++;
            }
            else{
                d[(e[i][1])-1]++;
            }
        }
        max=min=d[0];
        for ( i = 0; i < n; i++)
        {
            if(d[i]>max) max=d[i];
            if(d[i]<min) min=d[i];
        }
        cout<<(max-min)<<"\n";
        for(i=0;i<n;i++){
            cout<<i+1<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
