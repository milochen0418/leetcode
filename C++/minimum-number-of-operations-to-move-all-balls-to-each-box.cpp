class Solution {
    //https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
public:
    vector<int> minOperations(string boxes) {
        vector<int> anss;
        int n = boxes.size();
        for(int i = 0; i<n;i++) {
            int ans=0;
            for(int j = 0;j<n;j++) ans += abs(i-j)*(boxes[j]=='1');
            anss.push_back(ans);
        }
        return anss;
    }
};