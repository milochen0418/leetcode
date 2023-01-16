class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        queue<int> q;
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front()+3000 < t) q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */