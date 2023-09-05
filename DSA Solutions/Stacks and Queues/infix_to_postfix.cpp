class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char op){
        switch(op){
            case '(': return 0;
            case '+': return 1;
            case '-': return 1;
            case '*': return 2;
            case '/': return 2;
            case '^': return 3;
        }
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<char> operators;
        string res="";
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                res.push_back(s[i]);
            }else if(s[i]=='('){
                operators.push('(');
            }else if(s[i]==')'){
                while(operators.top()!='('){
                    res.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
            }else{
                while(!operators.empty() && priority(operators.top())>=priority(s[i]) && s[i]!='('){
                    res.push_back(operators.top());
                    operators.pop();
                }
                operators.push(s[i]);
            }
        }
        
        while(!operators.empty()){
            res.push_back(operators.top());
            operators.pop();
        }
        
        return res;
    }
};