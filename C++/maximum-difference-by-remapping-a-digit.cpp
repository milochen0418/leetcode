class Solution {
    //https://leetcode.com/problems/maximum-difference-by-remapping-a-digit
public:
    int minMaxDifference(int num) {
        string maxs = to_string(num), mins = maxs;
        int n = maxs.length();
        for(int i = 0; i<n;i++)  {
            if(maxs[i] != '9') {
                char c = maxs[i];
                for(int j = i;j<n;j++) if(maxs[j]==c) maxs[j]='9';
                break;
            }
        }
        char c = mins[0];
        for(int j= 0; j<n;j++) if(mins[j]==c) mins[j]='0';
        return stoi(maxs) - stoi(mins);
    }
};