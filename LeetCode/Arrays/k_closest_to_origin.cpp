// https://leetcode.com/problems/k-closest-points-to-origin/
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

class Solution {
public:
    vector<pair<double,vector<int>>> distances;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue <pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pqueue;
        calcDistances(points);
        for(pair<double,vector<int>> distance : distances){
            pqueue.push({distance.first,distance.second});
        }
        for(int i=0;i<k;i++){
            vector<int> temp=pqueue.top().second;
            pqueue.pop();
            res.push_back(temp);
        }
        return res;
    }
    void calcDistances(vector<vector<int>>& points){
        for(vector<int> point : points){
            double dis=sqrt(pow(point[0],2)+pow(point[1],2));
            distances.push_back({dis,point});
        }
        return;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points,res;
    points={
        {9997,9997},{9996,9998}
    };
    res=s.kClosest(points,1);
    for(auto i : res){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}