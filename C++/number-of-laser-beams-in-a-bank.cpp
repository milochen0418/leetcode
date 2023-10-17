class Solution {
    //https://leetcode.com/problems/number-of-laser-beams-in-a-bank
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        
        vector<int> cnts = {0};
        for(int i = 0; i<n; i++) {
            int cnt = 0;
            for(auto &c: bank[i])
                if(c=='1') cnt++;
            if(cnt>0) 
                cnts.push_back(cnt);
        }
        int ans =0;
        for(int i = 0; i<cnts.size()-1;i++) 
            ans+=cnts[i]*cnts[i+1];
        return ans;
    }
};