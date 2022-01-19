class Solution {
    //https://leetcode.com/problems/burst-balloons
public:
    //Hash key method for unordered_map
    //https://jimmy-shen.medium.com/stl-map-unordered-map-with-a-vector-for-the-key-f30e5f670bae
    //https://stackoverflow.com/questions/10405030/c-unordered-map-fail-when-used-with-a-vector-as-key
    //Dynamic Programming refer
    //https://leetcode.com/explore/featured/card/dynamic-programming/630/an-introduction-to-dynamic-programming/4035/
    struct VectorHasher {
        int operator()(const vector<int> &V) const {
            int hash = V.size();
            for(auto &i : V) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };    
    
    int maxCoins(vector<int>& nums) {
        unordered_map<vector<int>,string,VectorHasher> mp;
        

        return 0;    
    }
};