class Solution {
public:
    vector<int> a;
    bool canJump(vector<int>& nums) {
        a = nums;
        return sol(0);
        
    }
    bool sol(int i) {
        int n = a.size();
        if(i>=n) return false;
        if(i==n-1) return true;
        bool ans = false;
        for(int j = 1;j<=a[i];j++) ans |= sol(i+j);  
        return ans;
    }
};