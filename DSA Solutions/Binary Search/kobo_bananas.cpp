// https://leetcode.com/problems/koko-eating-bananas/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int max=*max_element(piles.begin(),piles.end()),l=1,e=max,m,t=0,min;
        while(l<=e){
            m=(l+e)/2;
            t=0;
            for(int i: piles){
                if(i%m!=0){
                    t++;
                }
                t+=(i/m);
                cout<<i<<" "<<m<<" : "<<(long double)i/m<<" "<<ceil((double)i/m)<<" t:"<<t<<endl;
            }
            if(t<=h){
                min=m;
                e=m-1;
            }else{
                l=m+1;
            }
        }
        return min;
    }
};

int main(){
    Solution s;
    vector<int> piles={1000000000};
    cout<<s.minEatingSpeed(piles,2)<<endl;
    return 0;
}