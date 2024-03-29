class Solution {
    //https://leetcode.com/problems/decode-string
    //article https://leetcode.com/problems/decode-string/discuss/2282439/C%2B%2B-or-iterative-simple-solution-using-stack-or-23-lines
public:
    string decodeString(string s) {
        pair<int,string> e = {0,""};
        stack<pair<int,string>> stk;
        for(auto &c:s) {
            if(c>=0 && c<='9') 
                e.first = e.first*10+(int)(c-'0');
            else if(c=='[') {
                stk.push(e);
                e={0,""};
            } else if(c==']') {
                e.second = multi_append_string(stk.top().second, stk.top().first, e.second);
                stk.pop();
            } else
                e.second.push_back(c);                   
        }
        return e.second;
    }
    string& multi_append_string (string& orig, int mul, string& str) {
        for(int i = 0; i<mul;i++) orig.append(str);
        return orig;
    }


    string decodeStringVer01(string s) {
        int num = 0;
        string str="";
        string ans = "";
        stack<int> nstk;
        stack<string> sstk;
        int i;
        for(i=0;i<s.length();i++) {
            char c = s[i];
            if(c>=0 && c<='9') {
                //num=num*10+(int)(c-'0');
                //sstk.push(ans);
                sstk.push(str);
                printf("sstk.push(str=%s)\n", str.c_str());
                while(s[i]>='0' && s[i]<='9') {
                    num=num*10+(int)(s[i]-'0');
                    i++;
                }
            }
            /*
            if(c>=0 && c<='9') {
                //num=num*10+(int)(c-'0');
                while(s[i]>='0' && s[i]<='9') {
                    num=num*10+(int)(s[i]-'0');
                    i++;
                }
            } else 
                */
            c = s[i];
            if(c=='[') {
                nstk.push(num);
                //sstk.push(ans);
                num = 0;
                str = "";
                //str = ans;
            } else if(c==']') {
                int n = nstk.top(); 
                ans = sstk.top();
                printf("str= \"%s\", sstk.top() = \"%s\"\n", str.c_str(), ans.c_str());
                ans+=multi_string(n,str);
                str = ans;
                nstk.pop();
                sstk.pop();
            } else {
                str.push_back(c);
            }            
        }
        //return ans;
        return str;
        
    }
    string multi_string (int mul, string str) {
        printf("multi_string(mul=%d, str=%s)\n", mul, str.c_str());
        string ret = "";
        for(int i = 0; i<mul;i++) {
            ret = ret + str;
        }
        return ret;
    }
};