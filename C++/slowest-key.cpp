class Solution {
    //https://leetcode.com/problems/slowest-key
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.length();
        int maxv = -1;
        char maxc = 0;
        for(int i = n-1; i>=0;i--) {
            int prev=i==0?0:releaseTimes[i-1];
            int dur = releaseTimes[i]-prev;
            char c = keysPressed[i];
            if(dur>maxv || (dur==maxv && c>maxc)) {
                maxv = dur;
                maxc = c;
            }            
        }
        return maxc;        
    }
    char slowestKey_v01(vector<int>& releaseTimes, string keysPressed) {
        vector<int>& pressedTimes = releaseTimes;
        int n = keysPressed.length();
        
        //convert releaseTimes into pressedTime
        for(int i = releaseTimes.size()-1; i>=0;i--) {
            int prev=i==0?0:releaseTimes[i-1];
            pressedTimes[i]-=prev;
        }
        
        int maxv = -1;
        char maxc = 0;
        for(int i = 0;i<n;i++) {
            int dur=pressedTimes[i];
            char c = keysPressed[i];
            if(dur>maxv || (dur==maxv && c>maxc)) {
                maxv = dur;
                maxc = c;
            }
        }
        return maxc;
    }
};