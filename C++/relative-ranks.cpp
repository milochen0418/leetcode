class Solution {
    //https://leetcode.com/problems/relative-ranks
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<vector<int>> v = vector<vector<int>>(n,vector<int>(3,0));
        for(int i =0;i<n;i++) {
            v[i][0] = score[i];//score
            v[i][1] = i;//original idx
            //v[i][2] = 0;//sorted idx
        }
        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs){
           return lhs[0]> rhs[0];
        });
        for(int i =0;i<n;i++) v[i][2] = i;//sorted idx from large to small
        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs) {
            return lhs[1]<rhs[1];
        });
        vector<string> ans;
        for(auto &w:v) {
            if(w[2]>2) {
                ans.push_back(to_string(w[2]+1));
            } else {
                if(w[2]==0) ans.push_back("Gold Medal");    
                if(w[2]==1) ans.push_back("Silver Medal");
                if(w[2]==2) ans.push_back("Bronze Medal");
            }
        }
        return ans;
    }
};