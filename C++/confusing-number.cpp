class Solution {
    //https://leetcode.com/problems/confusing-number
    //article https://leetcode.com/problems/confusing-number/discuss/2983958/C%2B%2B-1-Pass-array-approach
public:
    bool confusingNumber(int n) {
        //After rorate 180 degree for the n to get m. if m is number and m!=n, 
        //then we say n is the confusing number. 
        int v = n;
        int m = 0; 
        vector<int> mp={0, 1,-1,-1,-1,-1, 9,-1, 8, 6};
                      //0. 1. 2. 3. 4. 5. 6. 7  8. 9
        while(v>0) {
            int i = v%10;
            if(mp[i]==-1) return false;
            m = m*10 + mp[i];
            v/=10;
        }
        return n!=m;
    }
};