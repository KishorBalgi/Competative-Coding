// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> nonRep;
		    map<char,int> repeats;
		    int i=0,n=A.length();
		    string res="";
		    while(i<n){
		        repeats[A[i]]++;
		        
		        while(!nonRep.empty() && repeats[nonRep.front()]>1){
		            nonRep.pop();
		        }
		        
		        if(repeats[A[i]]==1) nonRep.push(A[i]);
		        
		        if(!nonRep.empty()) res.append(1,nonRep.front());
		        else res.append(1,'#');
		        
		        i++;
		    }
		    
		    return res;
		}

};