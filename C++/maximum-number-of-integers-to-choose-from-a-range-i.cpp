class Solution {
    //https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i
    //article https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/discuss/4196191/C%2B%2B-simple-10-lines-by-hash-set
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bs;
        for(auto &i:banned) bs.insert(i);
        int sum = 0, ans =0;
        for(int i = 1; i <= n;i++) {
            if(bs.find(i) != bs.end()) continue;
            if(sum+i > maxSum) break;
            sum+=i;
            ans++;
        }
        return ans;
        
    }
};