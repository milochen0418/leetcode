class Solution {
    //https://leetcode.com/problems/word-break
    //article https://leetcode.com/problems/word-break/discuss/3106255/C%2B%2B-Trie-mixed-with-DP
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //Implement by Trie
        struct TNode {
            TNode(int _match=false) {
                match = _match;
                children = vector<TNode*> (26,nullptr);
            }
            ~TNode() {
                for(auto &child:children)
                    if(child!=nullptr)
                        delete child;
            }
            vector<TNode*> children;
            int match;
        };
        TNode* root = new TNode();// Trie root node
        function<void(string&)> T_insert = [&root](string &s) { 
            TNode* node = root;
            for(auto &c:s) {
                if(node->children[c-'a']==nullptr)
                    node->children[c-'a'] = new TNode();
                node = node->children[c-'a'];
            }
            node->match = true;   
        };
        
        for(auto &w: wordDict) T_insert(w);//Trie Insert

        int n = s.length();
        vector<int> dp = vector<int>(n,-1);
        function<int(int)> sol = [&](int i) {
            if(i>=n) return 1;
            if(dp[i]!=-1)return dp[i];
            TNode* node = root;
            dp[i]=0;
            for(int j=i;j<n;j++) {
                char c = s[j];
                if(node->children[c-'a'] == nullptr) break;
                node = node->children[c-'a'];
                if(node->match) dp[i] = dp[i] | sol(j+1);
                if(dp[j]>0) return dp[j];
            }
            return dp[i];
        };
        return sol(0);
    }


    bool wordBreak_v01(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        int n = s.length();
        vector<vector<int>>dp (n+1, vector<int>(n+1, -1));
        for(auto word: wordDict) words.insert(word);
        int val = wordbreak(s, words, dp,0,n);
        return val > 0;
    
    }
    
    int wordbreak_v02( const string& s, unordered_set<string>& words, vector<vector<int>>&dp,int i ,int j) {
        
        if(dp[i][j] > -1) return dp[i][j];
        if(i==j) return dp[i][j] = 1;
        
        int len = j-i;
        if(words.count(s.substr(i,len))>0) {
            dp[i][j] = 1;
            return dp[i][j];
        } else {
            dp[i][j] = 0;
            for(int k=i+1;k<j;k++) {
                dp[i][k] = wordbreak(s, words, dp, i,k);
                dp[k][j] = wordbreak(s, words, dp, k,j);
                dp[i][j] = max(dp[i][j], dp[i][k]*dp[k][j]);
            }
            return dp[i][j];
        }
    }
};