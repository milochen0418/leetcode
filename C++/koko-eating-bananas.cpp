class Solution {
    //https://leetcode.com/problems/koko-eating-bananas/
public:
    int test (vector<int>& piles, int H) {
        int low = 1, high = 1000000000, k = 0;
        while (low <= high) {
            k = (low + high) / 2;
            int h = 0;
            for (int i = 0; i < piles.size(); i ++) 
                h += ceil(1.0 * piles[i] / k);
            if (h > H)
                low = k + 1;
            else
                high = k - 1;
        }
        return low;        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        return test(piles,h); //answser from anothers
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int v: piles) {
            low = min(low,v);
            high = max(high,v);
        }
        low = low/h;
        low = max(1,low);
        
        
        int k = 0;
        while (low <= high) {
            k = (low + high) / 2;
            int ch = 0;
            for (int i = 0; i < piles.size(); i ++) 
                ch += ceil(1.0 * piles[i] / k);
            if (ch > h)
                low = k + 1;
            else
                high = k - 1;
        }
        return low;        
    }
};