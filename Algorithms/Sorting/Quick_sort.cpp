// Quick Sort:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void QuickSort(vector<int>& nums,int l,int h){
        if(l<h){
            int p = partation(nums,l,h);

            QuickSort(nums,l,p-1);
            QuickSort(nums,p+1,h);
        }
    }

    int partation(vector<int>& nums,int l,int h){
        int pivot=nums[l];
        int i=l,j=h+1;

        while(i<j){

            // Find a number larger than pivot:
            do{
                i++;
            }while(nums[i]<=pivot);

            // Find a number smaller than pivot:
            do{
                j--;
            }while(nums[j]>pivot);

            // Swap these smaller and larger numbers:
            if(i<j) swap(nums[i],nums[j]);
        }
        // Swap pivot with its sorted position:
        swap(nums[l],nums[j]);
        return j;
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
    sol.QuickSort(nums,0,nums.size()-1);
    cout<<"After Sorting: ";
    sol.printList(nums);
    return 0;
}

// Analysis:

// ✅ Complexity Analysis of Quick Sort:
// Time Complexity:

// Best Case: \omega (N * log N)
// Average Case: \Theta (N * logN)
// Worst Case: O(N2)
// Auxiliary Space: O(log(N))

// ✅ Advantages of Quick Sort:
// It is a divide-and-conquer algorithm that makes it easier to solve problems.
// It is efficient on large data sets.
// It has a low overhead, as it only requires a small amount of memory to function.

// ✅ Disadvantages of Quick Sort:
// It has a worst-case time complexity of O(N2), which occurs when the pivot is chosen poorly.
// It is not a good choice for small data sets.
// It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).