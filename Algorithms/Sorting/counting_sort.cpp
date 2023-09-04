// Counting Sort:

#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public: 
        void countingSort(vector<int>& arr,int range){
            vector<int> count(range,0);

            for(int i=0;i<arr.size();i++){
                ++count[arr[i]-1];
            }
            arr.clear();
            for(int i=0;i<range;i++){
                while (count[i])
                {
                    arr.push_back(i+1);
                    --count[i];
                }
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
    vector<int> arr={1,2,4,5,3,2,1,4,2};
    int range=5;
    Solution sol;
    sol.printArr(arr);
    sol.countingSort(arr,range);
    sol.printArr(arr);
}