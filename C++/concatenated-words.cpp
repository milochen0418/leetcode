class Solution {
    //https://leetcode.com/problems/concatenated-words
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> word_set;
        for(auto &w:words) word_set.insert(w);
        for(auto &s:words) {
            vector<string> wordDict;
            for(auto &w:word_set) if(w!=s) wordDict.push_back(w);
            if(wordBreak(s, wordDict)) ans.push_back(s);
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {            
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
        int ret = sol(0);
        //return sol(0);
        //delete root;
        return ret;
    }
};