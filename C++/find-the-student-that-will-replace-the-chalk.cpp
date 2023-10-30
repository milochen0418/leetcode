class Solution {
    //https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0,n = chalk.size();
        while(1) {
            if(chalk[i]>k) break;
            k-= chalk[i];
            i = (i+1)%n;
        }
        return i;
    }
};