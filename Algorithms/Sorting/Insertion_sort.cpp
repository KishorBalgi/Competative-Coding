// Insertion Sort:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void InsertionSort(vector<int>& nums){
        int n=nums.size(),j,key;

        for(int i=1;i<n;i++){
            j=i-1;
            key=nums[i];
            while(nums[j]>key && j>-1){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }
    }

    void printList(vector<int>& nums){
        for(int num: nums){
            cout<<num<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Solution sol;
    vector<int> nums={5,2,3,11,6,24,2,5,77,23};
    cout<<"Before Sorting: ";
    sol.printList(nums);
    sol.InsertionSort(nums);
    cout<<"After Sorting: ";
    sol.printList(nums);
    return 0;
}

// Analysis:

// ✅ Complexity Analysis of Insertion Sort:
// Time Complexity of Insertion Sort
// The worst-case time complexity of the Insertion sort is O(N^2)
// The average case time complexity of the Insertion sort is O(N^2)
// The time complexity of the best case is O(N).
// Space Complexity of Insertion Sort
// The auxiliary space complexity of Insertion Sort is O(1)

// ✅ Characteristics of Insertion Sort
// Stable
// This algorithm is one of the simplest algorithms with a simple implementation
// Basically, Insertion sort is efficient for small data values
// Insertion sort is adaptive in nature, i.e. it is appropriate for data sets that are already partially sorted.