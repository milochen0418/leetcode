class Solution {
    //https://leetcode.com/problems/distance-between-bus-stops
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start == destination) return 0;
        int total = 0, dist = 0;
        for(auto &i:distance) total+=i;
        int begin = min(start, destination);
        int end = max(start, destination);
        for(int i = begin;i<end;i++) dist+=distance[i];
        return min(dist, total-dist);      
    }
};