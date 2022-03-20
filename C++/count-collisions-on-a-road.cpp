class Solution {
    //https://leetcode.com/problems/count-collisions-on-a-road
public:
    int countCollisions(string s) {
        int ans = 0;
        int n = s.length();
        vector<int> siv; //S index vector
        for(int i=0; i<n;i++) {
            if( i+1<n && s[i] == 'R' && s[i+1] == 'L') {
                s[i] = s[i+1] = 'S';
                ans+=2;
            }
            if(s[i]=='S') siv.push_back(i);
        }
        
        //RRRRR S LLL  ...  RRRRRRSLLL RRRSLLL
        for(auto &idx:siv) {
            int i = idx-1;
            while(i>=0 && s[i]=='R') {
                ++ans;
                s[i--] = 'S';
            }
            
            i = idx+1;
            while(i<n && s[i]=='L') {
                ++ans;
                s[i++] = 'S';
            }
        }
        return ans;
    }
};