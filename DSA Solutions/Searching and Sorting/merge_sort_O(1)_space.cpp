// 

// O(N*M)
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=0,j=0;
            
            while(i<n && j<m){
                if(arr1[i]<arr2[j]) i++;
                else{
                    swap(arr1[i],arr2[j]);
                    for(int k=j;k<m-1;k++){
                        if(arr2[k]>arr2[k+1]) swap(arr2[k],arr2[k+1]);
                    }
                    i++;
                }
            }
        } 
};

// Using Gap Alogrithm: ceil(size/2) O((N+M)log(N+M))
