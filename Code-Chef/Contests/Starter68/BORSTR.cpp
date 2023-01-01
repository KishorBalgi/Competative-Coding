#include<iostream>
#include<math.h>
#include<string.h>
#include<set>
using namespace std;

bool checkSub(string s,int l,int h){
    for(int i=l;i<h;i++){
        if(s[i]!=s[i+1]){
            return 0;
        }
    }return 1;
}

// bool checkBoring(string s){
//     set<char> c;
//     for(int i=0;i<s.length();i++){
//         c.insert(s[i]);
//     }
//     if(c.size()>1)
//         return 0;
//     return 1;
// }

// bool checkSubOccur(string s,string sub,int l,int h,int len){
//     for(int i=l;i<=h;i++){
//         if(sub.compare(s.substr(i,len))==0){
//             return 1;
//         }
//     }
//     return 0;
// }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,len=0;
        string s;
        cin>>n;
        cin>>s;
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i+1;j++){
                if(checkSub(s,j,j+i-1)){
                    if(int index=s.find(s.substr(j,i)) != string::npos){
                        cout<<index<<endl;
                        if(index!=j){
                        len=i;
                        break;}
                    }
                }
            }
        }
        cout<<len<<'\n';
    }
    return 0;
}