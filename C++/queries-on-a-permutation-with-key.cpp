class Solution {
    //https://leetcode.com/problems/queries-on-a-permutation-with-key
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v = vector<int>(m,0);
        int n = queries.size();
        vector<int> ans;
        for(int i = 0; i<m ;i++) v[i] = i+1;
        for(auto &q:queries) {
            int idx = 0;
            for(idx = 0; idx<m; idx++) 
                if(v[idx] == q) break;
            ans.push_back(idx);
            for(int i = idx; i>=1;i--) 
                swap(v[i], v[i-1]);
        }
        return ans;
    }
};