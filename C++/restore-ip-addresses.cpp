class Solution {
    //https://leetcode.com/problems/restore-ip-addresses
public:
    stack<int> stk;//most 3 element that mean the index of first digit after dot
    string s;
    vector<vector<int>> ips;//legal ips, ips[k] is like {221,102,3,0}
    vector<string> restoreIpAddresses(string ss) {
        vector<string> ans;
        ips = {{255,255,11,135},{255,255,111,35}};
        s = ss;
        sol(1);//generate solution to ips in this backtracking
        for(auto &ip:ips) 
            ans.push_back(string_format("%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]));
        
        return ans;
    }
    void sol(int i) {
        return;
    }
    string string_format(const string fmt_str, ...) {
        int final_n, n = ((int)fmt_str.size()) * 2; 
        unique_ptr<char[]> formatted;
        va_list ap;
        while(1) {
            formatted.reset(new char[n]); 
            strcpy(&formatted[0], fmt_str.c_str());
            va_start(ap, fmt_str);
            final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
            va_end(ap);
            if (!(final_n < 0 || final_n >= n)) break;
            n += abs(final_n - n + 1);
        }
        return string(formatted.get());
    }    
};