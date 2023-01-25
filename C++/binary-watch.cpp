class Solution {
    //https://leetcode.com/problems/binary-watch
    //article https://leetcode.com/problems/binary-watch/discuss/3096859/C%2B%2B-DFS-solution-explanation
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        function<void(vector<int>)> add_time = [&](vector<int>bits){
            int h = bits[0]*8+bits[1]*4+bits[2]*2+bits[3]*1;
            int m = bits[4]*32+bits[5]*16+bits[6]*8+bits[7]*4+bits[8]*2+bits[9]*1;
            if(h>11 || m>59) return;
            string time;
            if(h/10==0) {
                time = "0:00";
                time[0] = '0'+h%10;
                time[2] = '0'+m/10;
                time[3] = '0'+m%10;
            } else {
                time = "00:00";
                time[0] = '0'+h/10;
                time[1] = '0'+h%10;
                time[3] = '0'+m/10;
                time[4] = '0'+m%10;
            }
            ans.push_back(time);
        };
        
        int n = 10;
        vector<int> stk;
        function<void(int,int)> sol=[&](int i, int r){
            if(r<0) return;
            if(i==n && r>0) return;
            if(i==n) {
                add_time(stk);
                return;
            }
            stk.push_back(1);
            sol(i+1,r-1);
            stk.pop_back();
            stk.push_back(0);
            sol(i+1,r);
            stk.pop_back();            
        };
        sol(0,turnedOn);
        //You can call sol(0,0..n);        
        return ans;
    }

    vector<string> readBinaryWatch_frameOnly(int turnedOn) {
        int n = 10;
        vector<int> stk;
        function<void(int,int)> sol=[&](int i, int r){
            if(r<0) return;
            if(i==n && r>0) return;
            if(i==n) {
                
                for(auto i:stk) printf("%d",i);
                printf("\n");
                return;
            }
            //r: remaind number of one that still not put in
            //i: range [i..n] begin index i to n=10
            
            stk.push_back(1);
            sol(i+1,r-1);
            stk.pop_back();
            stk.push_back(0);
            sol(i+1,r);
            stk.pop_back();            
        };
        sol(0,n);
        printf("\n");
        sol(0,0);
        printf("\n");
        sol(0,n-1);
        printf("\n");
        sol(0,1);
        printf("\n");
        
        //You can call sol(0,0..n);
        return vector<string>();
    }
};