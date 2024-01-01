// https://leetcode.com/problems/is-graph-bipartite

class Solution {
    private:
    bool dfs(int node,int c,vector<int>& color, vector<vector<int>>& graph){
        color[node]=c;
        for(int adjacentNode : graph[node]){
            if(color[adjacentNode]==-1){
                color[adjacentNode] = !c;
                if(dfs(adjacentNode,!c, color, graph)) return true;
            }else if (color[adjacentNode]==c) return true;
        }
        return false;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                bool res= dfs(i,0,color,graph);
                cout<<res<<endl;
                if(res) return false;
            }
        }

        return true;
    }
};