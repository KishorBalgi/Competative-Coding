// https://leetcode.com/problems/simplify-path/

#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res="";
        stack<string> names;
        int n=path.length(),i=0,j=0;
        while(i<n){
            if(path[i]=='/'){
                for(j=i+1;j<=n;j++){
                    if(path[j]=='/' || j==n){
                        string sub=path.substr(i+1,j-i-1);
                        if(sub=="..") {
                            if(!names.empty()) names.pop();
                        }else if(j-i!=1 && sub!=".") names.push(sub);
                        break;
                    }
                }
                i=j;
            }
        }

        while(!names.empty()){
            res="/"+names.top()+res;
            names.pop();
        }
        if(res=="") res="/";
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.simplifyPath("/a//b////c/d//././/..")<<endl;
    return 0;
}