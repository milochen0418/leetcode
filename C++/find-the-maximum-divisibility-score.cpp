class Solution {
    //https://leetcode.com/problems/find-the-maximum-divisibility-score
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int m = divisors.size();
        vector<int> scores = vector<int>(m,0);
        
        for(int i = 0; i<m; i++) 
            for(auto &v: nums)
                scores[i]+=(v % divisors[i] == 0);

        
        int max_idx = 0;
        for(int i = 0;i<m; i++) 
            if(scores[i]>scores[max_idx]) 
                max_idx = i;
            else if(scores[i]==scores[max_idx] && divisors[i]<divisors[max_idx])
                max_idx = i;
                
        return divisors[max_idx];
    }
};