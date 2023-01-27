class Solution {
    //https://leetcode.com/problems/concatenated-words
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
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
            int string_idx;//string index for input of findAllConcatenatedWordsInADict
        };
        TNode* root = new TNode();// Trie root node
        function<void(string&,int)> T_insert = [&root](string &s, int _string_idx ) { 
            TNode* node = root;
            for(auto &c:s) {
                if(node->children[c-'a']==nullptr)
                    node->children[c-'a'] = new TNode();
                node = node->children[c-'a'];
            }
            node->match = true;   
            node->string_idx = _string_idx;
        };
        for(int i = 0;i<words.size();i++) {
            T_insert(words[i], i); //Trie Insert
        }
        
        for(int i = 0;i<words.size();i++) {
            int outside_string_idx = i;
            string s=words[i];
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
                    if(node->match && node->string_idx!=outside_string_idx) dp[i] = dp[i] | sol(j+1);
                    if(dp[j]>0) return dp[j];
                }
                return dp[i];
            };
            int ret = sol(0);
            if(ret)ans.push_back(s);
        }
        return ans;
    }
};