class Solution {
    //https://leetcode.com/problems/count-number-of-teams/
    //article https://leetcode.com/problems/count-number-of-teams/discuss/4207613/C%2B%2B-explain-the-solution-from-brute-force-to-O(N2)
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans=0;
        vector<int> greater = vector<int>(n,0);
        vector<int> smaller = vector<int>(n,0);
        for(int j = 0;j<n;j++) {
            for(int k = j+1;k<n; k++) {
                if(rating[j]<rating[k]) smaller[j]++;
                if(rating[j]>rating[k]) greater[j]++;
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = i+1;j<n;j++) {
                if(rating[i]==rating[j]) continue;
                if(rating[i]<rating[j]) {
                    //for(int k = j+1;k<n;k++) ans+=(rating[j]<rating[k]);
                    ans+=smaller[j];
                } else {
                    //for(int k = j+1;k<n;k++) ans+=(rating[j]>rating[k]);
                    ans+=greater[j];
                }
            }
        }
        return ans;
    }
};