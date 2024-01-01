// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> res;
    void dfs(int node ,vector<int>& visited,vector<int> adj[]){
        visited[node] = 1;
        
        res.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        dfs(0,visited,adj);
        // Code here
        return res;
    }
};