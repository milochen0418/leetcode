class Solution {
    //https://leetcode.com/problems/most-visited-sector-in-a-circular-track
    //article https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/3001604/C%2B%2B-or-One-Pass
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int>ans;
        int m = rounds.size();
        for(int i = rounds[0];i!=rounds[m-1]; i=(i%n)+1)
            ans.push_back(i);
        ans.push_back(rounds[m-1]);
        sort(ans.begin(), ans.end());
        return ans;
    }
};