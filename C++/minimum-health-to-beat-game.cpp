class Solution {
    //https://leetcode.com/problems/minimum-health-to-beat-game
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int maxv = damage[0];
        int maxi = 0;
        int n = damage.size();
        for(int i = 1;i<n;i++) {
            if(damage[i] > maxv) {
                maxi = i;
                maxv = damage[i];
            }
        }
        if(damage[maxi] > armor) 
            damage[maxi] -=armor;
        else
            damage[maxi] = 0;
        
        long long ans =1;
        for(auto &i: damage)
            ans+=i;
        return ans;
    }
};