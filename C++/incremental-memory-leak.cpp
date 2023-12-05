class Solution {
    //https://leetcode.com/problems/incremental-memory-leak
    //article https://leetcode.com/problems/incremental-memory-leak/discuss/4366151/C%2B%2B-simple-3-lines-with-explain
public:
    vector<int> memLeak(int m1, int m2) {
        int i = 1;
        while(i<=m1||i<=m2) (m2>m1?m2:m1)-=i++;
        return {i,m1, m2};
    }

    vector<int> memLeak_v01(int memory1, int memory2) {
        int i = 1;
        while(true) {
            if(i>memory1  && i >memory2) break;
            if(memory2>memory1) {
                memory2-=i;   
            } else {
                memory1-=i;
            }
            i++;
        }
        return {i,memory1, memory2};
        
        
    }
};