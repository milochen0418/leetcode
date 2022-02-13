class Solution {
    // https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        if(n==1) return 0;
        int total_max = 0;
        if(true) {//even count first
            int odd_max = 0;
            int even_max = 0;
            int even_max_num = -1;
            unordered_map<int,int> even_mp;
            unordered_map<int,int> odd_mp;
            for(int i=0; i<n; i++) {
                if(i%2==0) {
                    even_mp[nums[i]]+=1;
                }
            }
            for(auto& [k,v]: even_mp){
                if(v>even_max){
                    even_max = max(even_max, v);
                    even_max_num = k;
                }
            }
            
            for(int i=0; i<n; i++) {
                if(i%2!=0) {
                    if(nums[i]!=even_max_num) {
                        odd_mp[nums[i]]+=1;
                    }
                }
            }
            
            for(auto& [k,v]: odd_mp){
                if(v>odd_max){
                    odd_max = max(odd_max, v);
                }
            }
            total_max = max(total_max,odd_max+even_max);
        }
        
        if(true) { //odd count first
            int odd_max = 0;
            int even_max = 0;
            int even_max_num = -1;
            unordered_map<int,int> even_mp;
            unordered_map<int,int> odd_mp;
            for(int i=0; i<n; i++) {
                if(i%2!=0) {
                    even_mp[nums[i]]+=1;
                }
            }
            for(auto& [k,v]: even_mp){
                if(v>even_max){
                    even_max = max(even_max, v);
                    even_max_num = k;
                }
            }
            
            for(int i=0; i<n; i++) {
                if(i%2==0) {
                    if(nums[i]!=even_max_num) {
                        odd_mp[nums[i]]+=1;
                    }
                }
            }
            
            for(auto& [k,v]: odd_mp){
                if(v>odd_max){
                    odd_max = max(odd_max, v);
                }
            }
            total_max = max(total_max,odd_max+even_max);
            
        }
        long ln = n;
        long lmax = total_max;
        return ln - lmax;
        return n-total_max;
        
        /*
        unordered_map<int,int> odd_mp;
        for(int i=0; i<n; i++) {
            if(i%2==0) {
                even_mp[nums[i]]+=1;
            } else {
                odd_mp[nums[i]]+=1;
            }
        }
        
        
        
        for(auto& [key, val] )
        
        
        for(auto& num:nums) s.insert(num);
        
        vector<int> v;
        for(auto &sn: s) v.push_back(sn);
        
        int vn = v.size();
        int max_val = INT_MIN;
        for(int i=0;i<vn;i++) {
            for(int j=0;j<vn;j++){
                if(i==j) continue;                
                int even_val = v[i];
                int odd_val = v[j];
                if( even_mp[even_val] + odd_mp[odd_val] > max_val) {
                    max_val = even_mp[even_val] + odd_mp[odd_val];
                }
            }
        }
        return n-max_val;
        return 0;
        */
    }
};