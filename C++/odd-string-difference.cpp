class Solution {
    //https://leetcode.com/problems/odd-string-difference
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };    
    string oddString(vector<string>& words) {
        unordered_set<vector<int>, VectorHash> s;
        for(int i = 0;i<3;i++) {
            vector<int> v0 = wordToVec(words[0]);
            vector<int> v1 = wordToVec(words[1]);
            vector<int> v2 = wordToVec(words[2]);
            s.insert(v0);
            s.insert(v1);
            s.insert(v2);
            if(s.size()>=2) {
                if(v0==v1) {
                    return words[2];
                } else {
                    if(v0==v2) 
                        return words[1];
                    else 
                        return words[0];
                }
            }
        }
        
        for(int i=3;i<words.size();i++) {
            vector<int> v = wordToVec(words[i]);
            s.insert(v);
            if(s.size() == 2) return words[i];
        }
        return "";
    }
    vector<int> wordToVec(string word) {
        vector<int> v=vector<int>(word.size()-1,0);
        for(int i = 1;i<word.length();i++) {
            v[i-1] = (int)(word[i] - word[i-1]);
        }
        return v;
    }
};