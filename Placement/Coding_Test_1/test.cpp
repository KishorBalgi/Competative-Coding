
/* Problem on removing 3 or more consecutive letters */

#include <bits/stdc++.h>
using namespace std;

string removeConsecutive(string s){
    int i = 0, j = 0;

    while(j < s.length()){
        if(s[j] == s[i])
            j++;
        else if(s[j] != s[i]){
            if(j - i >= 3){
                s.erase(i, (j - i));
                if(i - 1 <= 0)
                    i = 0;
                else
                    i = i - 1;
                j = i;
            }
            else{
                i++;
                j++;
            }
        }
        if(j == s.length() && j - i >= 3){
            s.erase(i, j - i);
        }

    }
    return s;
}


int main(){
    string s;
    cin >> s;

    string p = removeConsecutive(s);

    cout << p << endl;
}