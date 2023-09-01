// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<string> result;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<char> step={'D','U','R','L'};
    void backtracking(vector<vector<int>> &m,vector<vector<int>> &visited, int i,int j,string path){
        int n=m.size();
        cout<<i<<" "<<j<<" "<<path<<endl;
        if(i>=n || j>=n || i<0 || j<0 || visited[i][j]==1 || m[i][j]==0) return;

        if(i==n-1 && j==n-1){
            result.push_back(path);
            return;
        }
        visited[i][j]=1;
        
        int new_i,new_j;
        string new_path;
        for(int k=0;k<4;k++){
            new_i=i+dir[k][0];
            new_j=j+dir[k][1];
            new_path=path+step[k];
            backtracking(m,visited,new_i,new_j,new_path);
        }

        visited[i][j]=0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited(n,vector<int>(n,0));

        backtracking(m,visited,0,0,"");

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}