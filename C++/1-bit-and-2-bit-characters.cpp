class Solution {
    //https://leetcode.com/problems/1-bit-and-2-bit-characters
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(bits[n-1]==1) return false;
        for(int i = 0;i<n;i++) 
            if(bits[i]==1)
                i++;
            else if(i==n-1) 
                return true;
        return false;
    }
};