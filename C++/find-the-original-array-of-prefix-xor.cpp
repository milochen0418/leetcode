class Solution {
    //https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
public:
    /*
        Observation 
        Input: pref = [5,2,0,3,1]
              Output: [5,7,2,3,2]

        Explanation: From the array [5,7,2,3,2] we have the following:



        5 - pref[0] = 5.                       -> = Output[0]
        7 - pref[1] = 5 ^ 7 = 2.               -> 7 = 2^5       = pref[0]^pref[1] = Output[1]
        2 - pref[2] = 5 ^ 7 ^ 2 = 0.           -> 2 = 5^7^0     = pref[1]^pref[2] = Output[2]
        3 - pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.       -> 3 = 5^7^2^3   = pref[2]^pref[3] = Output[3]
        2 - pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.   -> 2 = 5^7^2^3^1 = pref[3]^pref[4] = Output[4]
    */
    
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        for(int i = n-1;i>0;i--) {
            pref[i] = pref[i] ^ pref[i-1];
        }
        return pref;
    }
};