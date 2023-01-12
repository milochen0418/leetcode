class Solution {
    //https://leetcode.com/problems/minimum-health-to-beat-game
    //article https://leetcode.com/problems/minimum-health-to-beat-game/discuss/3038140/C%2B%2B-One-Pass-O(N)-4-lines
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int n = damage.size(), maxv = damage[0], maxi = 0;
        long long ans =1+damage[0];
        for(int i = 1;i<n;ans+=damage[i++]) if(damage[i]>maxv) maxv = damage[maxi=i];
        return ans -= min(maxv, armor);
    }

    long long minimumHealth_v01(vector<int>& damage, int armor) {
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