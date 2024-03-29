class Solution {
    //https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
    //article https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/discuss/3178059/C%2B%2B-or-easy-1-line-solution-without-if-else
public:
    int countOdds(int low, int high) {
        /*
        low+=(1-low%2);
        high-=(1-high%2);
        return 1+(high-low)/2;
        */
        /*
        return 1+( (high-(1-high%2))-(low+(1-low%2)))/2;
        */
        /*
        return 1+( (high-(1-high%2))-low-1+low%2)/2;
        */
        /*
        return 1+( high-1+high%2 -low-1+low%2)/2;
        */
        /*
        return ( high+high%2 -low+low%2)/2;
        */
        return ( high-low +high%2+low%2)/2;
    }
    int countOddsVer03(int low, int high) {
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