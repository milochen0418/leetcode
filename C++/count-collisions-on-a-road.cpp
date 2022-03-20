class Solution {
    //https://leetcode.com/problems/count-collisions-on-a-road
    //article https://leetcode.com/problems/count-collisions-on-a-road/discuss/1866943/what-a-stupid-solution-i-like-this-problem
public:
    int countCollisions(string s) {
        int ans = 0;
        int n = s.length();
		//siv(S index vector) is to save all index of S after replace all "LR" to "SS"
        vector<int> siv; 
		
		//Step 1.
		//Replace all "LR" into "SS" and makeing the data of siv.
        for(int i=0; i<n;i++) {
            if( i+1<n && s[i] == 'R' && s[i+1] == 'L') {
                s[i] = s[i+1] = 'S';
                ans+=2;
            }
            if(s[i]=='S') siv.push_back(i);
        }
        
		//Step 2. 
        //Start to solve this problem RRRSLLL... RRSLLL ... RRRSLLL 
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