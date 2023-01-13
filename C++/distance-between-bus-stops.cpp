class Solution {
    //https://leetcode.com/problems/distance-between-bus-stops
    //article https://leetcode.com/problems/distance-between-bus-stops/discuss/3043265/C%2B%2B-One-Pass-O(N)
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = 0, dist = 0, begin = min(start, destination), end = max(start, destination);
        for(int i = 0;i<distance.size();i++) {
            total+=distance[i];
            if(i>=begin && i<end) dist+=distance[i];
        }
        return min(dist, total-dist);
    }

    int distanceBetweenBusStops_v01(vector<int>& distance, int start, int destination) {
        if(start == destination) return 0;
        int total = 0, dist = 0;
        for(auto &i:distance) total+=i;
        int begin = min(start, destination);
        int end = max(start, destination);
        for(int i = begin;i<end;i++) dist+=distance[i];
        return min(dist, total-dist);      
    }
};