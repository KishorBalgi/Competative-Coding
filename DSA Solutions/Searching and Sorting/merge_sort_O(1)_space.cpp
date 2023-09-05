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
class Solution{
    public:
        //Function to merge the arrays.
        void swapGrt(long long a[],long long b[],int i,int j){
            if(a[i]>b[j]){
                swap(a[i],b[j]);
            }
        }
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int len=m+n;
            int gap=len/2 + len%2;
            
            while(gap>0){
                int i=0,j=i+gap;
                
                while(j<len){
                    // If i in arr1 and j in arr2:
                    if(i<n && j>=n){
                        swapGrt(arr1,arr2,i,j-n);
                    }
                    // If Both in arr2
                    else if(i>=n && j>=n){
                        swapGrt(arr2,arr2,i-n,j-n);
                    }
                    else{
                        swapGrt(arr1,arr1,i,j);
                    }
                    i++;
                    j++;
                }
                if(gap==1) break;
                gap=gap/2 +gap%2;
            }
        } 
};