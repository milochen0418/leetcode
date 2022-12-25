class Solution {
public:
    //["hello","i","am","leetcode","hello"]
    // n=5, -1, 4  ...  idx 0,1.  abs(startIdx - idx),  n-abs(startIdx - idx)
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> idxs;
        
        for(int i = 0; i<n;i++) {
            if(words[i] == target) {
                idxs.push_back(i);
            }
        }
        
        if(idxs.size()==0) return -1;
        int ans = INT_MAX;
        
        for(auto &i:idxs) {
            int len = abs(startIndex - i);
            ans = min(ans, len);
            ans = min(ans, n-len);
        }
        return ans;
    }
};