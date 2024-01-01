// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> nodes;
        vector<int> visited(V,0);
        vector<int> bfs;
        
        if(V==0) return bfs;
        
        nodes.push(0);
        visited[0]=1;
        
        while(!nodes.empty()){
            int front = nodes.front();
            
            for(int node: adj[front]){
                if(!visited[node]){
                    visited[node]=1;
                    nodes.push(node);
                }
            }
            
            bfs.push_back(front);
            nodes.pop();
        }
        
        return bfs;
    }
};