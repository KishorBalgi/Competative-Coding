// https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
    private:
    void dfs(int node,vector<int>& vis,stack<int>& s,vector<int> adj[]){
        vis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,s,adj);
            }
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    vector<int> res;
	    stack<int> s;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(i,vis,s,adj);
	    }
	    
	    while(!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    
	    return res;
	}
};