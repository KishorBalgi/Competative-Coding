// https://practice.geeksforgeeks.org/problems/stack-permutations/1

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        
        int j=0;
        for(int a: A){
            s.push(a);
            while(!s.empty() && s.top()==B[j]){
                s.pop();
                j++;
            }
        }
        
        return s.empty();
    }
};