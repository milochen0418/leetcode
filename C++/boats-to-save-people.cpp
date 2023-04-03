class Solution {
    //https://leetcode.com/problems/boats-to-save-people
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n=people.size(), ans = 0,L=0,R=n-1;
        sort(people.begin(), people.end());
        while(L<=R) {
            if(people[L] + people[R] <= limit) {
                L++;
                R--;
                ans++;
            } else {
                R--;
                ans++;
            }
        }
        return ans;
    }
};