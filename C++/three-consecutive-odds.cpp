class Solution {
    //https://leetcode.com/problems/three-consecutive-odds
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(auto &i:arr) {
            cnt = i%2==0?0:cnt+1;
            if(cnt>=3) return true;
        }
        return false;
    }
};