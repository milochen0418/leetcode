class Solution {
    //https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score
public:
    int maxScore(vector<int>& nums) {
        typedef long long ll;
        int ans = 0; 
        vector<int> pos;
        vector<int> neg;
        for(auto &i:nums) {
            if(i== 0) ans++;
            if(i < 0) neg.push_back(i);
            if(i > 0) pos.push_back(i);
        }
        if(pos.size()==0) return 0;
        sort(neg.begin(), neg.end());
        reverse(neg.begin(), neg.end());
        
        ll sum = 0;
        for(auto &i: pos) sum += (ll)i;
        ans += pos.size();
        
        for(auto &i: neg) {
            sum+= (ll)i;
            if(sum>0) ans++;
            else 
                break;
        }
        return ans;        
    }
};