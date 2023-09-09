// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int findCeleb(int n,vector<vector<int> >& M){
        if(n==0) return -1;
        
        int id = findCeleb(n-1,M);
        
        if(id==-1) return n-1;
        
        else if(M[id][n-1]) return n-1;
        
        else if(M[n-1][id]) return id;
        
        return -1;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int id = findCeleb(n,M);
        
        if(id==-1) return -1;
        
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(id!=i){
                a+=M[id][i];
                b+=M[i][id];
            }
        }
        
        if(a==0 && b==n-1) return id;
        
        return -1;
    }
};