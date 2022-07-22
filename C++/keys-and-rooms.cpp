class Solution {
    //https://leetcode.com/problems/keys-and-rooms
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        int n = rooms.size();
        queue<int> Q;
        s.insert(0);
        for(auto&k:rooms[0]) if(s.find(k)==s.end()) Q.push(k);
        while(!Q.empty()) {
            int e = Q.front();
            Q.pop();
            s.insert(e);
            if(s.size()==n) return true;
            for(auto &k:rooms[e]) if(s.find(k)==s.end())Q.push(k);
        }
        return false;
    }
};