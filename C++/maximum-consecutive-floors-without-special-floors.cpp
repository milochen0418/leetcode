class Solution {
    //https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors
    //article https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/discuss/4194446/C%2B%2B-or-O(NlogN)-simple-9-line
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        vector<int> v;
        for(auto &i : special) {
            if(i>=bottom && i <= top) v.push_back(i);
        }
        v.push_back(bottom-1);
        v.push_back(top+1);
        sort(v.begin(), v.end());
        
        int n = v.size(), ans = 0;
        for(int i = 1; i<n;i++) {
            ans = max(v[i]-v[i-1]-1, ans);
        }
        return ans;
    }
};  