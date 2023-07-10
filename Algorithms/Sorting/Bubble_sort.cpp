// Bubble Sort:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void BubbleSort(vector<int>& nums){
        int n=nums.size();
        bool swapped=false;
        for(int i=0;i<n-1;i++){
            swapped=false;
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    swapped=true;
                }
            }

            // Terminate if already sorted:
            if(!swapped) break;
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
    sol.BubbleSort(nums);
    cout<<"After Sorting: ";
    sol.printList(nums);
    return 0;
}

// Analysis:

// ✅ Complexity Analysis of Bubble Sort:
// Time Complexity: O(N2)
// Auxiliary Space: O(1)

// ✅ Advantages of Bubble Sort:
// Bubble sort is easy to understand and implement.
// It does not require any additional memory space.
// It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.

// ✅ Disadvantages of Bubble Sort:
// Bubble sort has a time complexity of O(N2) which makes it very slow for large data sets.
// Bubble sort is a comparison-based sorting algorithm, which means that it requires a comparison operator to determine the relative order of elements in the input data set. It can limit the efficiency of the algorithm in certain cases.