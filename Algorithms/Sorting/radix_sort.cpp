// Radix Sort:

#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public: 
        int getMax(vector<int>& arr){
            int max=arr[0];
            for(int i=1;i<arr.size();i++){
                if(arr[i]>max) max=arr[i];
            }
            return max;
        }
        void countingSort(vector<int>& arr,int n,int place){
            vector<int> count(10,0);
            vector<int> sorted(n);

            // Count the occurences of each element:
            for(int i=0;i<n;i++){
                count[(arr[i]/place)%10]++;
            }

            // Store the actual positions of the items in output[]:
            for(int i=1;i<10;i++){
                count[i]+=count[i-1];
            }

            // Use stable way to place the items at the right position:
            for(int i=n-1;i>=0;i--){
                sorted[count[(arr[i]/place)%10]-1]=arr[i];
                count[(arr[i]/place)%10]--;
            }
            // Copy the sorted array to the arr:
            arr.clear();
            for(int ele: sorted){
                arr.push_back(ele);
            }
        }
        void radixSort(vector<int>& arr,int n){
            int max=getMax(arr);

            for(int place=1;max/place>0;place*=10){
                countingSort(arr,n,place);
            }
        }
        void printArr(vector<int> arr){
            for(int a: arr){
                cout<<a<<" ";
            }
            cout<<endl;
        }
};

int main(){
    vector<int> arr={170, 45, 75, 90, 802, 24, 2, 66};
    int n=8;
    Solution sol;
    sol.printArr(arr);
    sol.radixSort(arr,n);
    sol.printArr(arr);
}