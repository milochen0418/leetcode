class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int cnt=0;
        for(int j = 0; j<32; j++) {
            if( (n & (1<<j)) > 0) {
                cnt++;
            }
        }
        return cnt;
        
    }
};