class Solution {
    //https://leetcode.com/problems/apply-discount-to-prices
public:
    using ll = long long;
    string discountPrices(string sentence, int discount) {
        string &s = sentence;
        string ans = "";
        
        int n = s.length();
        string word = "";
        for(int i = 0; i<n;i++) {
            if(i+1>=n || s[i+1]==' ') {
                word.push_back(s[i]);
                string newword = getword(word, discount);
                for(auto &c: newword) ans.push_back(c);
                word = "";
            } else {
                if(s[i] == ' ') {
                    ans.push_back(' ');
                } else {
                    word.push_back(s[i]);
                }
                
            }
        }
        return ans;
    }
    
    
    char ff[(int)(1e5+50)];
    string getword(string& w, int discount) {
        //cout<<"getword w = "<<w<<'\n';
        int n = w.size();
        if(w.size()<=1) return w;
        if(w[0]!='$') return w;
        if(w[1]<'0' || w[1]>'9') return w;
        
        int cnt_point = 0;
        for(int i =1;i<n;i++) {
            if(w[i]=='.') {
                cnt_point++;
                continue;
            }
            if(w[i]<'0' || w[i]>'9') return w;
        }
        if(cnt_point>1) return w;
        string realnumber_str = w.substr(1);
        //processing precison
        
        //double val = stof(realnumber_str);
        //cout<<"val = "<<val<<'\n';
        //val = val * ((double)(100-discount)/(double)(100.0f));
        //cout<<"new val = "<<val<<'\n';
        //sprintf(ff, "$%.2lf",val);
        
        ll v = 0;
        ll div = 0;
        for(int i = 0; i<realnumber_str.size();i++){
            v = v*10 + (realnumber_str[i]-'0');
            if(realnumber_str[i] == '.') {
                if(i+2 < realnumber_str.size()) {
                    div = 2;
                    v = v*10 + realnumber_str[i+1]-'0';
                    v = v*10 + realnumber_str[i+2]-'0';
                } else if(i+1 < realnumber_str.size()) {
                    div = 1;
                    v = v*10 + realnumber_str[i+1]-'0';
                    div = 2;
                    v = v*10 + 0;
                } else {
                    div = 0;
                    v = v*100;
                    div = 2;
                }
            }
        }
        
        v = v*(100-discount);
        sprintf(ff, "$%lld.%02lld",v/100, v%100);
        
        
        
        string retw = string(ff);
        return retw;
        
    }
};