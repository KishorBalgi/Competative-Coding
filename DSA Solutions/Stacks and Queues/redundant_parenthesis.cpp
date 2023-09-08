// https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> p;
        int n=s.length();
        
        for(char ch: s){
            
            if(ch==')'){
                char top=p.top();
                p.pop();
                
                int count=0;
                while(top!='('){
                    count++;
                    top=p.top();
                    p.pop();
                }
                if(count<=1){
                    return 1;
                }
                
            }else p.push(ch);
        }
        
        return 0;
    }
};