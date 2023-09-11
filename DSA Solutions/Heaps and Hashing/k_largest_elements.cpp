// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int,vector<int>,greater<int>> pq;
	    vector<int> res;
	    int i=0;
	    for(i=0;i<k;i++){
	        pq.push(arr[i]);
	    }
	    
	    while(i<n){
	        if(pq.top()<arr[i]){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	        i++;
	    }
	    
	    while(!pq.empty()){
	        res.insert(res.begin(),pq.top());
	        pq.pop();
	    }
	    return res;
	    
	}

};