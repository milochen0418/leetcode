class Solution {
    //https://leetcode.com/problems/remove-interval
    //add article https://leetcode.com/problems/remove-interval/discuss/2637939/C%2B%2B-or-array-approach-or-simple-or-explanation
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int begin = toBeRemoved[0], end = toBeRemoved[1];
        for(auto &i: intervals) {
            if(i[1]<=end && i[0]>=begin) continue;
            if(i[0]>=end || i[1]< begin)
                ans.push_back(i);
            else {
                if(i[0] < begin) ans.push_back({i[0],begin});
                if(i[1] > end) ans.push_back({end,i[1]});                    
            }
        }
        return ans;
    }
};