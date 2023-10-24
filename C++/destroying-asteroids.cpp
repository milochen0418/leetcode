class Solution {
    //https://leetcode.com/problems/destroying-asteroids
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        typedef long long ll;
        ll m = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto &i:asteroids) {
            if(m<(ll)i) return false;
            m+=(ll)i;
        }
        return true;
    }
};