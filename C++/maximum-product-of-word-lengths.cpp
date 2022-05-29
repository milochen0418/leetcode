class Solution {
    //https://leetcode.com/problems/maximum-product-of-word-lengths
public:
    int maxProduct(vector<string>& words) {
        int ans, n = words.size();
        vector<vector<int>> v;
        for(int i = 0; i<n;i++){
            string &w = words[i];
            int val = 0;
            for(auto &c: w) val=val | (1<<(c-'a'));
            v.push_back( {(int)w.size(), val});
        }
        ans = 0;
        for(int i = 0; i<n;i++) {
            for(int j=i+1;j<n;j++) {
                vector<int>&a = v[i];
                vector<int>&b = v[j];
                if( (a[1] & b[1]) > 0) continue;
                ans = max(ans, a[0]*b[0]);
            }
        }
        return ans;        
    }
};