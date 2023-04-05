// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0,n=prices.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int temp=prices[j]-prices[i];
                max=temp>max?temp:max;
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<int> prices={7,6,4,3,1};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}