class Solution {
    //https://leetcode.com/problems/excel-sheet-column-number
    //article https://leetcode.com/problems/excel-sheet-column-number/discuss/1790152/C%2B%2B-or-right-to-left-without-map-or-power
public:
    int titleToNumber(string columnTitle) {
        string& s = columnTitle;
        int n = s.length();
        long long base = 1;
        long long sum = 0;
        for(int i=n-1;i>=0;i--) {
            sum += (s[i]-'A'+1) *base;
            base*=26;
        }
        return sum;        
    }
};