// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    int incMax=0,excMax=0,prevIncMax;
	    
	    for(int i=0;i<n;i++){
	        prevIncMax=incMax;
	        incMax=excMax+arr[i];
	        excMax=max(prevIncMax,excMax);
	    }
	    
	    return max(incMax,excMax);
	}
};