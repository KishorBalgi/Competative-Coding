#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            if(coins-costs[i]>=0){
                max+=1;
                coins-=costs[i];
            }
        }
        return max;
    }
};

int main(){
    vector<int> costs={1,6,3,1,2,5};
    Solution s;
    cout<<s.maxIceCream(costs,20)<<endl;
}