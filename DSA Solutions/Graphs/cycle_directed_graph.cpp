// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
    private:
    bool dfs(int node,vector<int> adj[],vector<int>& visited,vector<int>& path){
        
        visited[node]=1;
        path[node]=1;
        
        for(int adjacent : adj[node]){
            if(visited[adjacent] && path[adjacent]) return true;
            else if(!visited[adjacent]){
                if(dfs(adjacent,adj,visited,path)) return true;
            }
        }
        path[node]=0;
        return false;
        
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path)) return true;
            }
        }
        return false;
        
    }
};