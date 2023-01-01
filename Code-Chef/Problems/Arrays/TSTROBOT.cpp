#include <iostream>
#include <set>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        set<int> s;
        cin>>n>>x;
        string c;
        s.insert(x);
        cin>>c;
        for(int i=0;i<n;i++){
            if(c[i]=='R'){
                s.insert(++x);
            }else{
                s.insert(--x);
            }
        }
        cout<<s.size()<<endl;
    }
}

