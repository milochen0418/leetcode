class Solution {
    //https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for(int i = 0; i < n;i++) capacity[i]-=rocks[i];
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(capacity[i]>additionalRocks) break;
            ans++;
            additionalRocks-=capacity[i];
        }
        return ans;
    }

    int maximumBags_v01(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for(int i = 0; i < n;i++) {
            capacity[i]-=rocks[i];
        }   
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(capacity[i]==0) {
                ans++;
                continue;
            }
            int minus = min(capacity[i], additionalRocks);
            capacity[i] -= minus;
            additionalRocks -= minus;
            if(capacity[i]==0) {
                ans++;
                continue;
            } else {
                break;
            }
        }
        return ans;
    }
};