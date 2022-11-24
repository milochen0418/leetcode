class Solution {
    //https://leetcode.com/problems/strobogrammatic-number
public:
    bool isStrobogrammatic(string num) {
        int L = 0, R = num.length()-1;
        while(L<=R) {            
            if(num[L] == '8' && num[R]=='8')  {L++;R--;continue;}
            if(num[L] == '6' && num[R] =='9') {L++;R--;continue;}
            if(num[R] == '6' && num[L] =='9') {L++;R--;continue;}
            if(num[R] == '1' && num[L] =='1') {L++;R--;continue;}
            if(num[R] == '0' && num[L] =='0') {L++;R--;continue;}
            return false;
        }
        return true;
    }
};