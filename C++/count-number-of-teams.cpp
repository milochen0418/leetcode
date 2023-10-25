class Solution {
    //https://leetcode.com/problems/count-number-of-teams/
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans=0;;
        for(int i = 0; i<n; i++)
            for(int j = i+1;j<n;j++)
                for(int k = j+1;k<n;k++)
                    ans+=( (rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j]>rating[k]));
        return ans;      
    }
};