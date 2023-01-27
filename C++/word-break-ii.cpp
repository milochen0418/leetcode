class Solution {
    //https://leetcode.com/problems/word-break-ii
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
        vector<string> ans;
        vector<string> stk;
        
        function<string(vector<string>&)> convert = [](vector<string>& strs){
            string ret=strs[0];
            for(int i = 1;i<strs.size();i++) {
                ret.push_back(' ');
                ret.append(strs[i]);
            }
            return ret;
        };
        
        function<void(string&)> T_insert = [&root](string &s) { 
            TNode* node = root;
            for(auto &c:s) {
                if(node->children[c-'a']==nullptr)
                    node->children[c-'a'] = new TNode();
                node = node->children[c-'a'];
            }
            node->match = true;   
        };
        for(auto &w: wordDict) T_insert(w);
        
        int n = s.length();
        vector<int> dp = vector<int>(n,-1);
        function<int(int)> sol = [&](int i) {
            if(i>=n) {
                ans.push_back(convert(stk));
                return 1;
            }

            TNode* node = root;
            int dp_i = 0;
            for(int j=i;j<n;j++) {
                char c = s[j];
                if(node->children[c-'a'] == nullptr) break;
                node = node->children[c-'a'];
                if(node->match) {
                    stk.push_back(s.substr(i,j-i+1));
                    dp_i = sol(j+1);
                    stk.pop_back();
                }
            }
            return dp_i;
        };
        sol(0);
        return ans;
    }

};