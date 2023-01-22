class Solution {
    //https://leetcode.com/problems/sort-the-students-by-their-kth-score/
public:
    vector<vector<int>>& sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](auto&lhs, auto&rhs) {
            return lhs[k]>rhs[k];
        });
        return score;
    }
};