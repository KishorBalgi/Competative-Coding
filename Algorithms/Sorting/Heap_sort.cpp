// Heap Sort:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void HeapSort(vector<int>& nums){
        int n=nums.size();

        // Build heap:
        // i = n/2-1 remaining half contains leaf nodes:
        for(int i=n/2-1; i>=0; i--){
            heapify(nums,n,i);
        }

        // Sort:
        for(int i=n-1;i>0;i--){
            // Swap fist element with last element:
            swap(nums[0],nums[i]);

            // Heapify the reduced heap:
            heapify(nums,i,0);
        }

    }

    int heapify(vector<int>& nums,int n,int root){

        // Assume root as largest:
        int largest = root;
        int left= 2 * root +1;
        int right= 2 * root +2;
        // Check if left child is larger than root:
        if(left<n && nums[left]> nums[largest]) largest=left;

        // Check if right child is larger than root:
        if(right<n && nums[right]> nums[largest]) largest=right;
        
        // If largest is not root:
        if(largest != root){
            // Swap root and largest child:
            swap(nums[root],nums[largest]);

            // Recursively Heapify the affected sub tree:
            heapify(nums,n,largest);
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
    sol.HeapSort(nums);
    cout<<"After Sorting: ";
    sol.printList(nums);
    return 0;
}

// Analysis:

// ✅ Complexity Analysis of Heap Sort
// Time Complexity: O(N log N)
// Auxiliary Space: O(1)

// ✅ Important points about Heap Sort:
// Heap sort is an in-place algorithm. 
// Its typical implementation is not stable but can be made stable (See this)
// Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.

// ✅ Advantages of Heap Sort:
// Efficiency –  The time required to perform Heap sort increases logarithmically while other algorithms may grow exponentially slower as the number of items to sort increases. This sorting algorithm is very efficient.
// Memory Usage – Memory usage is minimal because apart from what is necessary to hold the initial list of items to be sorted, it needs no additional memory space to work
// Simplicity –  It is simpler to understand than other equally efficient sorting algorithms because it does not use advanced computer science concepts such as recursion.

// ✅ Disadvantages of Heap Sort:
// Costly: Heap sort is costly.
// Unstable: Heap sort is unstable. It might rearrange the relative order.
// Efficient: Heap Sort is not very efficient when working with highly complex data. 