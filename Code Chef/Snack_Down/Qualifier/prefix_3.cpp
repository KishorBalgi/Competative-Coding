#include <iostream>
#include <string>
#include <bits/stdc++.h>
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
            string s1,s2,x,p,q,str;
            int cnt=1,i,j,m,n;
            cin >> s1;
            cin >> s2;
            cin >> x;
            m=s1.length();
            n=s2.length();
            while(str==s1+s2){


            }
            cout<<cnt<<"\n";
       }
	return 0;
}

