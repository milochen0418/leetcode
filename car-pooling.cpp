class Solution {    
    //https://leetcode.com/problems/car-pooling
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> timestamp;
        for(auto& trip:trips) {
            int trip_1_val = (timestamp.find(trip[1]) != timestamp.end()) ? timestamp[trip[1]] : 0;
            timestamp[trip[1]] = trip_1_val + trip[0];
            int trip_2_val = (timestamp.find(trip[2]) != timestamp.end()) ? timestamp[trip[2]] : 0; 
            timestamp[trip[2]] = trip_2_val - trip[0];
        }
        
        int used_capacity = 0;
        for(auto& [key,value]:timestamp) {
            used_capacity += value;
            if( used_capacity > capacity) {
                return false;
            }
        }
        return true;   
    }
};