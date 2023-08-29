// https://practice.geeksforgeeks.org/problems/print-diagonally4331/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> res;
		int i=0,a,b;
		while(i<N){
		    a=0; b=i;
		    while(a<=i && b>=0){
		        res.push_back(A[a][b]);
		        a++;
		        b--;
		    }
		    i++;
		}
		
		i=1;
		while(i<N){
		    a=i; b=N-1;
		    while(a<=N-1 && b>=1){
		        res.push_back(A[a][b]);
		        a++;
		        b--;
		    }
		    i++;
		}
		
		return res;
	}

};

int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}
