class Solution {
    //https://leetcode.com/problems/count-number-of-teams/
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans=0;;
        printf("n = %d\n",n);
        for(int i = 0; i<n; i++) {
            for(int j = i+1;j<n;j++) {
                if(rating[i]==rating[j]) continue;
                if(rating[i]<rating[j]) {
                    for(int k = j+1;k<n;k++) ans+=(rating[j]<rating[k]);
                } else {
                    for(int k = j+1;k<n;k++) ans+=(rating[j]>rating[k]);
                }
            }
        }
        return ans;
    }
    int numTeams_v01(vector<int>& rating) {
        int n = rating.size(), ans=0;;
        for(int i = 0; i<n; i++)
            for(int j = i+1;j<n;j++)
                for(int k = j+1;k<n;k++)
                    ans+=( (rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j]>rating[k]));
        return ans;      
    }
};