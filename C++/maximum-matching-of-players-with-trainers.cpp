class Solution {
    //https://leetcode.com/problems/maximum-matching-of-players-with-trainers
    //article https://leetcode.com/problems/maximum-matching-of-players-with-trainers/discuss/4353873/C%2B%2B-or-time-O(MlogM%2BNlogN)
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i =0,j=0,m=players.size(), n=trainers.size(), ans=0;
        while(i<m && j<n) {
            int t = trainers[j], p = players[i];
            if(p<=t) 
                ans++, i++, j++;
            else
                j++;
        }
        return ans;
    }
};