// Merge Sort:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void MergeSort(vector<int>& nums,int l,int h){
        if(l<h){
            int m=(l+h)/2;
            MergeSort(nums,l,m);
            MergeSort(nums,m+1,h);
            merge(nums,l,m,h);
        }
    }

    void merge(vector<int>& nums,int l,int m,int h){
        vector<int> merged(h-l+1,0);

        int i=l,j=m+1,k=0;
        while(i<=m && j<=h){
            if(nums[i]<nums[j]){
                merged[k++]=nums[i++];
            }else{
                merged[k++]=nums[j++];
            }
        }

        while(i<=m){
            merged[k++]=nums[i++];
        }

        while(j<=h){
            merged[k++]=nums[j++];
        }

        i=l;
        for(int num : merged){
            nums[i]=num;
            i++;
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
    sol.MergeSort(nums,0,nums.size()-1);
    cout<<"After Sorting: ";
    sol.printList(nums);
    return 0;
}

// Analysis:

// ✅ Complexity Analysis of Merge Sort:
// Time Complexity: O(N log(N)),  Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation. 

// T(n) = 2T(n/2) + θ(n)

// The above recurrence can be solved either using the Recurrence Tree method or the Master method. It falls in case II of the Master Method and the solution of the recurrence is θ(Nlog(N)). The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

// Auxiliary Space: O(N), In merge sort all elements are copied into an auxiliary array. So N auxiliary space is required for merge sort.

// ✅ Applications of Merge Sort:
// Sorting large datasets: Merge sort is particularly well-suited for sorting large datasets due to its guaranteed worst-case time complexity of O(n log n).
// External sorting: Merge sort is commonly used in external sorting, where the data to be sorted is too large to fit into memory.
// Custom sorting: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data.
// Inversion Count Problem

// ✅ Advantages of Merge Sort:
// Stability: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
// Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN), which means it performs well even on large datasets.
// Parallelizable: Merge sort is a naturally parallelizable algorithm, which means it can be easily parallelized to take advantage of multiple processors or threads.

// ✅ Drawbacks of Merge Sort:
// Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process. 
// Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
// Not always optimal for small datasets: For small datasets, Merge sort has a higher time complexity than some other sorting algorithms, such as insertion sort. This can result in slower performance for very small datasets.