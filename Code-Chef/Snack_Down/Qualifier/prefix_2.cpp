#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
// #include <bits/stdc++.h>
using namespace std;

int isSubstring(string a,string b){
       if(b.find(a)!=string::npos)
            return 1;
       return 0;
       
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        char s1[1000],s2[1000];
        string x,p,q,str;
        int cnt=0,i,j,m,n;
        scanf("%s %s",s1,s2);
        cin>>x;
        m=strlen(s1);
        n=strlen(s2);

        for(i=-1;i<m;i++){
            i==-1?p="":p+=s1[i];
            for(j=-1;j<n;j++){
                j==-1?q="":q+=s2[j];
                str=p+q;
                cnt+=isSubstring(str,x);
            }
            q="";
        }
        cout<<cnt<<"\n";
    }
return 0;
}

