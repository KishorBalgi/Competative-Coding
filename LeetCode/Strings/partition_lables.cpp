// https://leetcode.com/problems/partition-labels/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length(),i=0,j=n-1,k=i+1,l=0;
        vector<int> res;
        while(k<n && i<n && j<n){
            while(i<=j && s[i]!=s[j]){
                j--;
            }
            k=i+1;
            while(k<j && j!=n){
                l=j+1;
                while(l<n){
                    if(s[k]==s[l]) j=l;
                    l++;
                }
                k++;
            }
            res.push_back(j-i+1);
            i=j+1;
            j=n-1;
            // for(int i : res) cout<<i<<" ";
        }
        return res;
    }
};

int main(){
    Solution sol;
    for(int i : sol.partitionLabels("caedbdedda")) cout<<i<<" ";
    return 0;
}

// We can solve this problem using hashmap as: https://leetcode.com/problems/partition-labels/solutions/1868842/java-c-visually-explaineddddd/
