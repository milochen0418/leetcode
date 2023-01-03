class Solution {
    //https://leetcode.com/problems/delete-columns-to-make-sorted
public:
    int minDeletionSize(vector<string>& strs) {
        int num = 0, m = strs.size(), n = strs[0].length();
        for(int j = 0;j<n;j++) {
            num++;
            for(int i = 1;i<m;i++) {
                if(strs[i][j] < strs[i-1][j]) {
                    num--;
                    break;
                }
            }
        }
        return n-num;
    }
};