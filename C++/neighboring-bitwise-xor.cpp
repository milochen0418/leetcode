class Solution {
    //https://leetcode.com/problems/neighboring-bitwise-xor/
public:
    bool doesValidArrayExist(vector<int>& derived) {
        /*
        [1,1,0]
        case start from 0
        [0,1,0]
        case start from 1
        [1,0,1]
        
        [1,0]
        case start from 0
        [0,1]
        case start from 1
        [1,0]
        
        
        [0,1] 
        [1,1]        
        */
        int n = derived.size();
        //case start from 0
        vector<int> orig = vector<int>(n,0);
        orig[0] = 0;
        for(int i = 0; i<n-1; i++) {
            orig[i+1] = orig[i]^derived[i];
        }
        if((orig[n-1]^derived[n-1]) == orig[0]) return true;
        
        orig[0] = 1;
        for(int i = 0; i<n-1; i++) {
            orig[i+1] = orig[i]^derived[i];
        }
        if((orig[n-1]^derived[n-1]) == orig[0]) return true;
        return false;
        
        
    }
};