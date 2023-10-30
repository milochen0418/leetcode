class Solution {
    //https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers
public:
    int minPartitions(string n) {
        char maxc ='0';
        for(auto &c: n) maxc = max(maxc,c);
        return maxc-'0';
    }
};