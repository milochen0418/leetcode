class Solution {
    //https://leetcode.com/problems/watering-plants
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int next_idx=0, n = plants.size(), ans=n, curr_capacity;
        while(curr_capacity = capacity) { 
            while(curr_capacity >= plants[next_idx]) {
                curr_capacity -= plants[next_idx++];
                if(next_idx>=n) return ans;
            }
            ans += 2*next_idx;
        }
        return ans;
    }
};