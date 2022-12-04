class Solution {
    //https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
public:
    typedef unsigned long long ull; 
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        ull sum = 0;
        for(auto&i:skill) sum+=(ull)i;
        ull num_team = n/2;
        if((sum % num_team) != 0) return -1;
        ull team_sum = sum/num_team;
        int i_team_sum = (int) team_sum;
        sort(skill.begin(), skill.end());
        int L=0,R=n-1;
        ull ans = 0;
        while(L<=R) {
            int valL = skill[L++];
            int valR = skill[R--];
            if(valL+valR != i_team_sum) return -1;
            ans = ans + (ull)(valL*valR);
        }
        return ans;
        
    }
};