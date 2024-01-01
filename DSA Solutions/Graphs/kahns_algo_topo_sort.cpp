// https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    queue<int> nodes;
	    vector<int> res;
	    
	   // Add Indegrees:
	   for(int i=0;i<V;i++){
	       for(int a : adj[i]){
	           indegree[a]++;
	       }
	   }
	   
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0) nodes.push(i);
	   }
	   
	   while(!nodes.empty()){
	       int front = nodes.front();
	       res.push_back(front);
	       nodes.pop();
	       
	       for(int a : adj[front]){
	           indegree[a]--;
	           if(indegree[a]==0) nodes.push(a);
	       }
	   }
	    return res;
	}
};