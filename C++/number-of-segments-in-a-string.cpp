class Solution {
    //https://leetcode.com/problems/number-of-segments-in-a-string
public:
    int countSegments(string s) {
        int ans = 0, state = 0;//0:unknown, 1:space, -1:non-space
        for(auto &c:s) {
            if(state!=-1 && c!=' ') ans++, state = -1;
            if(state==-1 && c==' ') state = 1;
        }
        return ans;
    }

    int countSegment_v01(string s) {
        int ans = 0;
        int state = 0;//0:unknown, 1:space, -1:non-space
        
        for(auto &c:s) {
            switch(state) {
                case 1:
                case 0:
                    if(c!=' ') {
                        ans++;
                        state = -1;
                    }
                    break;
                case -1:
                    if(c==' ') {
                        state = 1;
                    }
                break;
            }
        }
        return ans;
    }
};