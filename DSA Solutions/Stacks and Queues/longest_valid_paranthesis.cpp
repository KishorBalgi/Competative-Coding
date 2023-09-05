// https://practice.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

class Solution{
public:
    int maxLength(string S){
        // code here
        stack<int> s;
        s.push(-1);
        
        int i=0,res=0,count;
        
        while(i<S.length()){
            if(S[i]=='(') s.push(i);
            else{
                s.pop();
                if(!s.empty()){
                    res=max(i-s.top(),res);
                }else{
                    s.push(i);
                }
            }
            i++;
        }
        
        return res;
    }
};