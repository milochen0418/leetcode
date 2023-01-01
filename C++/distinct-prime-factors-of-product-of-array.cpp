class Solution {
public:
    
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ss;
        for(auto &num:nums) {
            int n = num;
            int i = 2;
            while( n > 1 ){
                while( n%i == 0 ){
                    ss.insert(i);
                    n = n/i;
                }
                i = i+1;
            }
        }
        return ss.size();
    }
    
    
};