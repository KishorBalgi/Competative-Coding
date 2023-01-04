// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rounds=0,temp;
        map<int,int> counts;
        for(int i:tasks){
            ++counts[i];
        }
        for(const auto &item:counts){
            if(item.second==1) return -1;
            temp=item.second;
            if(temp%3==0)
                rounds+=temp/3;
            else{
                rounds+=temp/3+1;
            }
            
        }
        return rounds;
    }
};

int main(){
    vector<int> tasks={66,66,63,61,63,63,64,66,66,65,66,65,61,67,68,66,62,67,61,64,66,60,69,66,65,68,63,60,67,62,68,60,66,64,60,60,60,62,66,64,63,65,60,69,63,68,68,69,68,61};
    Solution obj;
    cout<<obj.minimumRounds(tasks)<<endl;

}