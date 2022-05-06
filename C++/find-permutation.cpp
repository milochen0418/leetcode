class Solution {
    //https://leetcode.com/problems/find-permutation/
    //Article https://leetcode.com/problems/find-permutation/discuss/2014316/C%2B%2B-or-Array-Approach-or-Explanation
public:
    vector<int> findPermutation(string s_tmp) {
        /*
        I [1,2]
        DI [2,1,3]
        DDI [3,2,1,4]
        DDII [3,2,1,4,5]
        DDIID [3,2,1,4,6,5]
        DDIIDD [3,2,1,4,7,6,5]
        DDIDD [3,2,1,6,5,4]
        DDIDDDIDDDDI [3,2,1,7,6,5,4,12,11,10,9,8,13]
        DDIDDDIDDDDII [3,2,1,7,6,5,4,12,11,10,9,8,13,14]
        DDIDDDIDDDDIII [3,2,1,7,6,5,4,12,11,10,9,8,13,14,15]
        IDDIDDDIDDDDIIIDD [3,2,1,7,6,5,4,12,11,10,9,8,13,14,17,16,15]
        */
        //The key point is to process How many IDD...D 
        vector<int> ans = vector<int>();
        string s = "I" + s_tmp;
        int n = s.length();
        int cnt = 0;
        
        for(int i = 0;i<n+1;i++) {
            int start_idx=i ;
            while(i<n && s[i]=='D') i++;
            int end_idx = i;
            for(int j = end_idx;j>=start_idx;j--) {
                if(j>0)ans.push_back(j);
            }                
        }
        return ans;
    }
};