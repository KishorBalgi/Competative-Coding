#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> r;
        sort(nums.begin(),nums.end());
        int i=0,j,k,n=nums.size(),needed=0;
        j=i+1; k=n-1;
        while(i!=n-2){
            needed=0-nums[i];
            j=i+1;
            k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    r.insert(temp);
                    j++;k--;
                }else if(nums[j]+nums[k]<needed){
                    j++;
                }else{
                    k--;
                }
            }
            i++;
        }
        for(auto i:r){
            res.push_back(i);
        }
        return res;
    }
};

int main(){
    vector<int> nums={0,0,0,0};
    vector<vector<int>> result;
    Solution s;
    result=s.threeSum(nums);
    for(auto i:result){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }

}