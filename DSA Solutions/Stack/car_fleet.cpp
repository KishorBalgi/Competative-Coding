// https://leetcode.com/problems/car-fleet/description/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<typeinfo>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> sorted;
        stack<pair<int,int>> fleets;
        for(int i=0;i<speed.size();i++){
            sorted.push_back({position[i],speed[i]});
        }
        sort(sorted.rbegin(),sorted.rend());
        for(auto i : sorted){
            if(!fleets.empty()){
                pair<int,int> top=fleets.top();
                float s1=(float)(target-top.first)/top.second;
                float s2=(float)(target-i.first)/i.second;
                if(s2<=s1){
                    fleets.pop();
                    fleets.push(top.second<=i.second?top:i);
                }else{
                    fleets.push(i);
                }
            }else{
                fleets.push(i);
            }
        }

        return fleets.size();
    }
};

int main(){
    Solution s;
    int target=10;
    vector<int> pos={6,8},spd={3,2};
    cout<<s.carFleet(target,pos,spd)<<endl;
    return 0;
}