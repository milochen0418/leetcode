class Solution {
    //https://leetcode.com/problems/distribute-candies-to-people
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans = vector<int>(num_people,0);
        int idx = 0;
        int cnt = 1 ;
        while(candies>0) {
            int assign = min(candies, cnt);
            ans[idx]+=assign;
            candies-=assign;
            cnt++;
            idx=(idx+1)%num_people;
        }
        return ans;
    }
};