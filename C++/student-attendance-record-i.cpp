class Solution {
    //https://leetcode.com/problems/student-attendance-record-i
public:
    bool checkRecord(string s) {
        //A<2. no consecutive L>2 day
        //LAL is true
        int Acnt=0;
        int Lcnt=0;
        for(auto &c:s) {
            if(c=='L') {
                if(++Lcnt>=3) return false;
            } else {
                Lcnt=0;
                if(c=='A') if(++Acnt>=2) return false;
            }
        }
        return true;
    }
};