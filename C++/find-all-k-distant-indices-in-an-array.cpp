class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> disv = vector<bool>(n,false);
        for(int i=0;i<n;i++) if(nums[i]==key) {
            disv[i] = true;
            for(int j = max(i-k,0); j<=min(i+k,n-1);j++) {
                disv[j]=true;
            }
        }
        vector<int> ans;
        for(int i = 0; i< n;i++) if(disv[i]) {
            ans.push_back(i);
        }
        return ans;        
    }
};