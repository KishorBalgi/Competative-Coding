// https://leetcode.com/problems/non-decreasing-subsequences/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> s;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp={};
        backTracking(nums,0,temp);
        for(auto i:s){
            res.push_back(i);
        }
        return res;
    }
    void backTracking(vector<int>& a,int ind,vector<int>& temp){
        if(ind==a.size()){
            if(temp.size()>1){
                    s.insert(temp);
            }
            return;
        }
        int curr,prev;
        curr=a[ind];
        prev=temp.size()==0?-101:temp[temp.size()-1];

        if(curr>=prev){
            temp.push_back(curr);
            backTracking(a,ind+1,temp);
            temp.pop_back();
            backTracking(a,ind+1,temp);
        }else{
            backTracking(a,ind+1,temp);
        }
        return;
    }
};

int main(){
    Solution s;
    vector<int> a={4,6,7,7};
    vector<vector<int>> res;
    res=s.findSubsequences(a);
    for(vector<int> a: res){
        for(int num: a)
            cout<< num<<" ";
        cout<<'\n';
    }
    return 0;
}