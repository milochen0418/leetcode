class Solution {
    //https://leetcode.com/problems/largest-odd-number-in-string
    //article https://leetcode.com/problems/largest-odd-number-in-string/discuss/2934977/C%2B%2B-or-O(N)-or-explanation
public:
    string largestOddNumber(string num) {
        int n = num.length(), i=n-1;
        while(i>=0) {
            if( (num[i]-'0')%2==1 ) break;//find first odd value from right
            i--;
        }
        string ans; 
        for(int j = 0;j<=i;j++)ans.push_back(num[j]);
        return ans;
    }
};