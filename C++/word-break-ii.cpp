class Solution {
    //https://leetcode.com/problems/word-break-ii
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &w: wordDict) {
            T_insert(w);
        }
        
        
        
        
        return vector<string>();
    }
private:
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
    TNode* root = new TNode();
    
    TNode* T_find(string &s) {
        TNode* node = root;
        for(auto &c:s) {
            if(node->children[c-'a'] == nullptr) return nullptr;
            node = node->children[c-'a'];
        }
        return node;        
    }
    void T_insert(string &s) {
        TNode* node = root;
        for(auto &c:s) {
            if(node->children[c-'a']==nullptr)
                node->children[c-'a'] = new TNode();
            node = node->children[c-'a'];
        }
        node->match = true;   
    }
};