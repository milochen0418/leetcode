class Solution {
    //https://leetcode.com/problems/rotate-string
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        goal.append(goal);
        if(goal.find(s) != string::npos) return true;
        return false;
    }
};