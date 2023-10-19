class Solution {
    //https://leetcode.com/problems/watering-plants
    //article https://leetcode.com/problems/watering-plants/discuss/4186354/C%2B%2B-or-simple-9-lines-Simulate
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