class Solution {
public:
    int splitNum(int num) {
        
        //4325
        //2 3
        // 4 5
        // 5 4
        
        string tmps = to_string(num);
        string s;
        for(auto &c: tmps) if(c!='0') s.push_back(c);
        sort(s.begin(), s.end()) ;
        vector<int> ans = vector<int>(2,0);
        int idx = 0;
        for(auto &c:s) {
            ans[idx] = ans[idx]*10 + c-'0';
            idx = (idx + 1)%2;
        }
        return ans[0]+ans[1];
        
    }
};