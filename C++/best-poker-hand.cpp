class Solution {
    //https://leetcode.com/problems/best-poker-hand
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int is_flush=1,maxv = 0;
        for(auto &c:suits) if(c!=suits[0]) is_flush=false;
        if(is_flush) return "Flush";
        vector<int> v(14,0);
        for(auto &i:ranks) maxv = max(maxv, ++v[i]);
        if(maxv>=2) return maxv>=3?"Three of a Kind":"Pair";
        return "High Card";
    }    

    string bestHand_v01(vector<int>& ranks, vector<char>& suits) {
        if(is_flush(ranks, suits)) return "Flush";
        int v = max_repeat_rank(ranks, suits);
        if(v>=2) return v>=3?"Three of a Kind":"Pair";
        return "High Card";
    }
    bool is_flush(vector<int>& ranks, vector<char>& suits){
        for(auto &c:suits) if(c!=suits[0]) return false;
        return true;
    }
    int max_repeat_rank(vector<int>& ranks, vector<char>& suits){
        vector<int> v(14,0);
        int maxv = 0;
        for(auto &i:ranks) maxv = max(maxv, ++v[i]);
        return maxv;
    }
    
};