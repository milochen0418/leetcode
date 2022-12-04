class Solution {
    //https://leetcode.com/problems/remove-letter-to-equalize-frequency/
public:
    bool equalFrequency(string word) {
        vector<int> v = vector<int>(26,0);//frequency of each letter
        vector<int> w = vector<int>(26,0);
        for(auto &c:word) v[c-'a']++;
        
        unordered_set<int> s;
        for(auto &i:v) s.insert(i);//0,1,10
        //if(s.size() !=3) return false;
        //printf("Yeah~~\n");
        if(s.find(0)!=s.end() && s.find(1)!=s.end()) return true;
        return false;
        
        
        for(int i = 0; i<v.size();i++) w[v[i]]++;
        for(auto &i:w) if(i==1) return true;
        return false;
    }
};