class Solution {
    //https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
public:
    int countOdds(int low, int high) {
        low+=(1-low%2);
        high-=(1-high%2);
        return 1+(high-low)/2;
    }

    int countOddsVer02(int low, int high) {
        return (high-low+(low%2)+1)/2;
    }

    int countOddsVer01(int low, int high) {
        if(low%2==0) 
            high-=low;
        } else {
            high=high-low+1;
        }
        return (high+1)/2;
    }

};