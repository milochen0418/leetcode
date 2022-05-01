class Solution {
    //https://leetcode.com/problems/remove-digit-from-number-to-maximize-result
public:
    string removeDigit(string number, char digit) {
        int pos = -1, n = number.size();
        for(int i = n-1; i>=0;i--) {
            if((number[i] == digit) && (pos == -1 || number[i+1]>number[i])) {
                pos = i;
            }
        }
        return number.erase(pos,1);
    }
};