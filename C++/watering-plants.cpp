class Solution {
    //https://leetcode.com/problems/watering-plants
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int next_idx = 0;
        int n = plants.size();
        while(1) {
            int curr_capacity = capacity; 
            while(curr_capacity >= plants[next_idx] ) {
                ans = ans + 1;
                curr_capacity -= plants[next_idx];
                next_idx = next_idx+1;
                if(next_idx>=n) return ans;
            }
            ans += 2*next_idx;
        }
        return ans;
    }
};