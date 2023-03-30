// 
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class MinStack {
public:
    vector<int> stack,min;
    MinStack() {
        // min= pow(2,31) - 1;
    }
    
    void push(int val) {
        stack.push_back(val);
        if(min.empty() || stack.back()<min.back()) min.push_back(stack.back()); 
        else min.push_back(min.back());
    }
    
    void pop() {
        stack.pop_back();
        min.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
};

int main(){    
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-1);
    cout<<obj->getMin()<<endl;
    cout<<obj->top()<<endl;
    obj->pop();
    cout<<obj->getMin()<<endl;
    return 0;
}