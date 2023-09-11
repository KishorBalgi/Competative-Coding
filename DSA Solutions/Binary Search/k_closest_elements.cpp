// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    int maxVal=100000;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size(),l=0,h=n-k,m=0;
        
        while(l<h){
            m=(l+h)/2;
            if(x - arr[m]<=arr[m+k]-x){
                h=m;
            }else{
                l=m+1;
            }
        }

        return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};