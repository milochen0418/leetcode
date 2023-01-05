class Solution {
    //https://leetcode.com/problems/path-crossing
public:
    struct vector_hasher {
        int operator()(const vector<int> &V) const {
            long hash = V.size();
            for(auto &i : V) {
                hash ^= (i + 0x9e3779b9 + (hash << 6) + (hash >> 2)) % INT_MAX;
            }
            return hash;
        }
    };    
    
    bool isPathCrossing(string path) {
        vector<int> pos ={0,0};
        unordered_set<vector<int>, vector_hasher> s;
        s.insert(pos);
        for(auto &c:path) {
            if(c=='N') pos[1]--;
            else if(c=='S') pos[1]++;
            else if(c=='W') pos[0]++;
            else if(c=='E') pos[0]--;
            if(s.find(pos) != s.end()) return true;
            s.insert(pos);
        }
        
        return false;
    }
};