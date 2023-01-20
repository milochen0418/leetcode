class Solution {
    //https://leetcode.com/problems/self-dividing-numbers
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        function<int(int)> sol = [](int val){
            int n = val;
            while(n>0) {
                int d=n%10;
                if(d==0 || val%d!=0)return 0;
                n/=10;
            }
            return 1;            
        };
        for(int i =left;i<=right;i++) if(sol(i))ans.push_back(i);
        return ans;
    }
};