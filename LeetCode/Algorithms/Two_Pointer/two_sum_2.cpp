// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan&id=algorithm-i

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i=0,n=numbers.size(),j=n-1,sum=0;
        while(i<j){
            sum=numbers[i]+numbers[j];
            if(sum==target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }else if(sum>target){
                j--;
            }else{
                i++;
            }
        }
        return res={-1,-1};
    }
};

int main(){
    Solution s;
    vector<int> numbers={2,7,11,15}, res;
    res=s.twoSum(numbers,9);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}