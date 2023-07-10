// Selection Sort:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void SelectionSort(vector<int>& nums){
        int n=nums.size(),min_ind;

        for(int i=0;i<n-1;i++){
            min_ind=i;

            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[min_ind]) min_ind=j;
            }

            swap(nums[i],nums[min_ind]);
        }
    }

    void swap(int& a, int& b){
        int temp=a;
        a=b;
        b=temp;
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
    sol.SelectionSort(nums);
    cout<<"After Sorting: ";
    sol.printList(nums);
    return 0;
}

// Analysis:

// ✅ Complexity Analysis of Selection Sort:
// Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:

// One loop to select an element of Array one by one = O(N):
// Another loop to compare that element with every other Array element = O(N)
// Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N2)
// Auxiliary Space: O(1) as the only extra memory used is for temporary variables while swapping two values in Array. The selection sort never makes more than O(N) swaps and can be useful when memory writing is costly. 

// ✅ Advantages of Selection Sort Algorithm:
// Simple and easy to understand.
// Works well with small datasets.

// ✅ Disadvantages of the Selection Sort Algorithm
// Selection sort has a time complexity of O(n^2) in the worst and average case.
// Does not work well on large datasets.
// Does not preserve the relative order of items with equal keys which means it is not stable.