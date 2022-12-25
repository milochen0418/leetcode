class Solution {
    //https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(),ans = INT_MAX;
        for(int i = 0; i<n;i++) 
            if(words[i] == target) {
                int len = abs(startIndex - i);
                ans = min(ans, len);
                ans = min(ans, n-len);
            }
        return ans==INT_MAX?-1:ans;
    }

    //["hello","i","am","leetcode","hello"]
    // n=5, -1, 4  ...  idx 0,1.  abs(startIdx - idx),  n-abs(startIdx - idx)
    int closetTarget_v01(vector<string>& words, string target, int startIndex) {
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