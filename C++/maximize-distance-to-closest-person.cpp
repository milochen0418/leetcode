class Solution {
    //https://leetcode.com/problems/maximize-distance-to-closest-person
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> v;
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 1) {
                v.push_back(i);
            }
        }
        int last = (seats.size()-1) - v[v.size()-1];
        int first = v[0];
            
        int max_dist = max(first, last);
        for(int i = 0; i<v.size()-1;i++) {
            max_dist = max(max_dist,  (v[i+1] - v[i]) / 2);
        }
        return max_dist;
    }
};