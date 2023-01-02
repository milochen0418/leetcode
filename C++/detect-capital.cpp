class Solution {
    //https://leetcode.com/problems/detect-capital
    //Article https://leetcode.com/problems/detect-capital/discuss/1714403/C%2B%2B-or-O(N)
    //article https://leetcode.com/problems/detect-capital/discuss/2983807/C%2B%2B-1-Pass-O(N)-with-explanation
public:
    bool detectCapitalUse(string word) {
        int cnt = 0,n=word.length();
        for(auto &c:word) if('A'<=c && c<='Z') cnt++;
        return cnt==0 || cnt==n || (cnt==1 && word[0]<='Z');
    }
    bool detectCapitalUse_v01(string word) {
        const char* str = word.c_str();
        int i = 0;
        bool shouldAllLowerCase = false;
        bool shouldAllUpperCase = false;
        while(str[i]!='\0') {
            char c = str[i];
            bool is_lower_case = (c>='a' && c<='z');
            bool is_upper_case = (c>='A' && c<='Z');
            if(i==0) {
                shouldAllLowerCase = is_lower_case;
            } else if(i==1){
                if(shouldAllLowerCase && is_upper_case) return false;
                if(!shouldAllLowerCase)shouldAllUpperCase = is_upper_case;
            } else {
                if(shouldAllLowerCase && is_upper_case) return false;
                if(shouldAllUpperCase && is_lower_case) return false;
                if(!shouldAllUpperCase && is_upper_case) return false;
            }
            i++;
        }
        return true;
    }
};