class Solution {
    //https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
public:
    int countOdds(int low, int high) {
        if(low%2==0) 
            high-=low;
        } else {
            high=high-low+1;
        }
        return (high+1)/2;
    }
};