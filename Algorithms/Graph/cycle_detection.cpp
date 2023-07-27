#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
        int v;
        vector<vector<int>> graph;
    
    public:
        void createGraph(int v){
            this->v=v;
            graph.resize(v);
        }
        void addEdge(int u,int v){
            graph[u].push_back(v);
        }

        void printGraph(){
            for(vector<int> i: graph){
                for(int j:i) cout<<j<<" ";
                cout<<endl;
            }
        }

        // DFS: (another approach is graph coloring)
        bool isCyclicDFS(int node,vector<bool>& visited){
            if(visited[node]==true) return true;
            
            visited[node]=true;
            for(int i: graph[node]){
                return isCyclicDFS(i,visited);
            }
        }

};

int main(){
    Solution sol;
    sol.createGraph(4);
    sol.addEdge(0, 1);
    sol.addEdge(0, 2);
    sol.addEdge(1, 2);
    sol.addEdge(2, 0);
    sol.addEdge(2, 3);
    sol.addEdge(3, 3);
    sol.printGraph();
    vector<bool> visited(false);
    if(sol.isCyclicDFS(0,visited))
        cout<<"Cycle Exists"<<endl;
    else
        cout<<"Cycle Does Not Exists"<<endl;
    return 0;
}