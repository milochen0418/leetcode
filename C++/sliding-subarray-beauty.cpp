class Solution {
    //https://leetcode.com/problems/sliding-subarray-beauty/
    //article https://leetcode.com/problems/sliding-subarray-beauty/discuss/3447738/C%2B%2B-O(N)-sliding-window-%2B-counting
public:
    vector<int> getSubarrayBeauty_LTE(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int>& A=nums;
        int n = A.size();
        for(int i = 0;i<=n-k;i++) {
            vector<int> v;
            for(int j =i;j<i+k;j++) v.push_back(A[j]);
            sort(v.begin(), v.end());
            ans.push_back(min(v[x-1],0));
        }
        return ans;        
    }
    
    vector<int> getSubarrayBeauty_ans(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int> mp(102,0);
        vector<int>& A=nums;
        function<int(vector<int>&, int)> sol = [](vector<int>& mp, int x){
            int cnt = 0;
            for(int i = 0;i<mp.size();i++) {
                cnt += mp[i];
                if(cnt>=x) {
                    int ans = i-50;
                    return min(ans,0);
                }
            }
            return -1;            
        };
        int n = A.size();
        for(int i = 0; i<k;i++) {
            mp[A[i]+50]++;
        }
        ans.push_back(sol(mp,x));
        for(int i = k; i<n;i++) {
            mp[A[i-k]+50]--;
            mp[A[i]+50]++;
            ans.push_back(sol(mp,x));
        }   
        return ans;
        return vector<int>();
        
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        return getSubarrayBeauty_ans(nums,k,x);
    }
};