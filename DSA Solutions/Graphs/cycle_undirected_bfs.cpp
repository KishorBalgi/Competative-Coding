// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
    private:
    bool bfs(int node,vector<int> adj[],vector<int> visited){
        visited[node]=1;
        queue<pair<int,int>> nodes;
        nodes.push({node,-1});
        
        while(!nodes.empty()){
            int front = nodes.front().first;
            int parent = nodes.front().second;
            
            nodes.pop();
            
            for(int adjacent: adj[front]){
                if(!visited[adjacent]){
                    visited[adjacent]=1;
                    nodes.push({adjacent, front});
                }else if(adjacent != parent ) return true;
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)) return true;
            }
        }
        return false;
    }
    
};