class Solution {
    //https://leetcode.com/problems/keys-and-rooms
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return canVisitAllRooms_dfs(rooms);
        //return canVisitAllRooms_bfs(rooms);
    }
    
    int n;
    unordered_set<int> visited;
    vector<vector<int>> *pRooms;
    bool canVisitAllRooms_dfs(vector<vector<int>>& rooms) {
        pRooms = &rooms;
        n = rooms.size();
        dfs(0);
        return n==visited.size();
    }
    void dfs(int room) {
        visited.insert(room);
        vector<int>& keys = (*pRooms)[room];
        for(auto &key:keys) {
            if(visited.find(key) == visited.end()) {
                dfs(key);
            }
        }
    }


    bool canVisitAllRooms_bfs(vector<vector<int>>& rooms) {
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