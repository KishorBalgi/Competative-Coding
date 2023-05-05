// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buy=100000;
        for(int i=0;i<prices.size();i++){
            buy=min(buy,prices[i]);
            maxProfit=max(maxProfit,prices[i]-buy);
        }
        return maxProfit;
    }
};

int main(){
    Solution s;
    vector<int> prices={7,1,5,3,6,4};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}