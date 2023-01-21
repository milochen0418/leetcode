class Solution {
    //https://leetcode.com/problems/restore-ip-addresses
public:
    stack<int> stk;//most 3 element that mean the index of first digit after dot
    string s;
    vector<int> octets;
    vector<string> ans;
    vector<string> restoreIpAddresses(string ss) {
        s = ss;       
        sol();
        return ans;
    }
    void sol() {
        int n = s.length();
        int prev_idx=stk.empty()?0:stk.top();
        for(int len = 1;len<=3 && prev_idx+len-1<n;len++) {
            if(stk.size()==3 && prev_idx+len-1!=n-1) continue;
            string octetstr = s.substr(prev_idx,len);
            if(legal_octet_str(octetstr)) {
                stk.push(prev_idx+len);
                octets.push_back(stoi(octetstr));
                if(octets.size()==4) {
                    vector<int>& ip = octets;
                    ans.push_back(string_format("%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]));
                } else {
                    sol();
                }
                octets.pop_back();
                stk.pop();                
            }
        }
        return;
    }
    int legal_octet_str(string str) {
        int n = str.length();
        if(n==0) return 0;
        if(str[0]=='0') return n<=1;
        int octet_val = stoi(str);
        if(octet_val>255) return 0;
        return 1;
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