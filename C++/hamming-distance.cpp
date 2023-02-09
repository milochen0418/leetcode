class Solution {
    //https://leetcode.com/problems/hamming-distance
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        if(x<y) swap(x,y);
        while(x>0 && y >0) {
            if(x%2 != y%2) cnt++;
            x/=2;
            y/=2;
        }
        while(x>0) {
            cnt+=x%2;
            x/=2;
        }
        return cnt;      
    }
};