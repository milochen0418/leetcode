class Solution {
    //https://leetcode.com/problems/prime-in-diagonal
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        /*
        [01,02,03],
        [05,06,07],
        [09,10,11]
        //1, 3, 6, 9, and 11
        */ 
        unordered_set<int> s;
        int n = nums.size();
        for(int i = 0; i<n;i++) {
            s.insert(nums[i][i]);
            s.insert(nums[i][n-i-1]);
        }
        vector<int> v;
        for(auto &i:s) if(i>=2) v.push_back(i);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());//decreasing order
        
        function<int(int)> is_prime = [](int n) {
            for(int i = 2;i<n;i++) {
                if(n%i==0) return 0;
            }
            return 1;
        };
        for(auto &i:v) if(is_prime(i))return i;
        return 0;
    }
};