class Solution {
    //https://leetcode.com/problems/palindrome-partitioning
public:
    vector<vector<string>> partition(string s) {
        function<int(string&)> is_palindrome=[&](string &s){
            int L=0,R=s.length()-1;
            while(L<R) if(s[L++]!=s[R--])return 0;
            return 1;            
        }; //The lambda for checking string is palindrome or not.         
        int n = s.length();//there will be number of n-1 , max(n)=16. max(n-1)=15
        if(n==1) return vector<vector<string>>(1,vector<string>(1,s));
        int m = 1<<(n-1);
        vector<vector<string>> ans;
        for(int i = 0; i<m;i++) {
            int is_partition_legal = 1;
            vector<string> vs;
            string e="";
            for(int j = 0;j<n-1;j++) {
                e.push_back(s[j]);
                if((i&1<<j)!=0) {
                    if(!is_palindrome(e)) {
                        is_partition_legal = 0;
                        break;
                    }
                    vs.push_back(e);
                    e="";
                }
            } 
            if(!is_partition_legal) continue;
            e.push_back(s[n-1]);
            if(!is_palindrome(e)) continue;
            vs.push_back(e);
            ans.push_back(vs);
        }
        return ans;
    }

    vector<vector<string>> partition_v01(string s) {
        
        int n = s.length();//there will be number of n-1 , max(n)=16. max(n-1)=15
        if(n==1) return vector<vector<string>>(1,vector<string>(1,s));
        int m = 1<<(n-1);
        vector<vector<string>> ans;
        for(int i = 0; i<m;i++) {
            vector<string> vs;
            string e="";
            for(int j = 0;j<n-1;j++) {
                e.push_back(s[j]);
                if((i&1<<j)!=0) {
                    vs.push_back(e);
                    e="";
                }
            }
            e.push_back(s[n-1]);
            vs.push_back(e);
            //check this partition here. 
            int is_partition_legal = 1;
            for(auto &str:vs) {
                if(!is_palindrome(str)){
                    is_partition_legal=false;
                    break;
                }
            }
            
            if(is_partition_legal) ans.push_back(vs);
        }
        return ans;
    }
    int is_palindrome(string &s) {
        int L=0,R=s.length()-1;
        while(L<R) if(s[L++]!=s[R--])return 0;
        return 1;
    }
};