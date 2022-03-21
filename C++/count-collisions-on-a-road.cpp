class Solution {
    //https://leetcode.com/problems/count-collisions-on-a-road
    //article https://leetcode.com/problems/count-collisions-on-a-road/discuss/1866943/what-a-stupid-solution-i-like-this-problem
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5168075553214894/
public:
    int countCollisions(string s) {
        int S_cnt=0, L_cnt=0, R_cnt=0, n = s.length();
        for(int i=0;i<n;i++) if(s[i]=='S') ++S_cnt;
        for(int i=0;i<n && s[i]=='L';i++) ++L_cnt;
        for(int i=n-1; i>=0 && s[i]=='R';--i) ++R_cnt;
        return n-S_cnt-L_cnt-R_cnt;
    }
    int answer1(string s) {
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