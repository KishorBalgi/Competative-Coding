#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int isSubstring(string a,string b){
       int i,j;
       int m=a.length();
       int n=b.length();
       string str;
       str="";
       if(m<=n)
              for(i=0;i<n;i++){
                     for(j=i;j<i+m;j++){
                           str+=b[j];
                     }
                     if(str==a)
                            return 1;
                     str="";
              }
       return 0;
       
}

int main() {
	ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       int t;
       cin>>t;
       while(t--){
            string s1,s2,x,p,q,str;
            int cnt=1,i,j,m,n;
            cin >> s1;
            cin >> s2;
            cin >> x;
            m=s1.length();
            n=s2.length();
            str="";
            for(j=0;j<n;j++){
                   str+=s2[j];
                   cnt+=isSubstring(str,x);
            }
            str="";
            for(j=0;j<m;j++){
                   str+=s1[j];
                   cnt+=isSubstring(str,x);
            }
            str=p=q="";
            i=j=0;
              for(i=0;i<m;i++){
                     p+=s1[i];
                     for(j=0;j<n;j++){
                            q+=s2[j];
                            str=p+q;
                            cnt+=isSubstring(str,x);
                     }
                     q="";
              }
              cout<<cnt<<"\n";
       }
	return 0;
}

