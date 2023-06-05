// https://leetcode.com/problems/prison-cells-after-n-days/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        set<string> days;
        int size=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            vector<int> nextDay(8,0);
            for(int j=1;j<7;j++){
                nextDay[j]=cells[j-1]==cells[j+1]?1:0;
            }
            string s(nextDay.begin(),nextDay.end());
            if(days.find(s)!=days.end()){
                flag=true;
                break;
            }else{
                size++;
                days.insert(s);
            }
            cells=nextDay;
        }
        if(flag){
            n=n%size;
            for(int i=0;i<n;i++){
                vector<int> nextDay(8,0);
                for(int j=1;j<7;j++){
                    nextDay[j]=cells[j-1]==cells[j+1]?1:0;
                }
                cells=nextDay;
            }
            return cells;
        }
        return cells;
    }
};

int main(){
    Solution sol;
    vector<int> cells={1,0,0,1,0,0,1,0};
    for(int i : sol.prisonAfterNDays(cells,1000000000)) cout<<i<<" ";
    return 0;
}