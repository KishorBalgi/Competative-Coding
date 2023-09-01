// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void combinationsUtil(vector<int>&nums,vector<int>& data,int r,int i){
        if(i>nums.size()) return;
        if(data.size()==r){
            for(int num: data)
                cout<<num<<" ";
            cout<<endl;
            return;
        }

        data.push_back(nums[i]);
        combinationsUtil(nums,data,r,i+1);

        data.pop_back();
        combinationsUtil(nums,data,r,i+1);
    }
    void printCombinations(vector<int> nums,int r){
        vector<int> data;

        combinationsUtil(nums,data,r,0);
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    sol.printCombinations(nums,2);
    return 0;
}