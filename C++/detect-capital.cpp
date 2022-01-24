class Solution {
    //https://leetcode.com/problems/detect-capital
public:
    bool detectCapitalUse(string word) {
        const char* str = word.c_str();
        int i = 0;
        bool shouldAllLowerCase = false;
        bool isFirstUpperCase = false;
        bool shouldAllUpperCase = false;
        while(str[i]!='\0') {
            char c = str[i];
            bool is_lower_case = (c>='a' && c<='z');
            bool is_upper_case = (c>='A' && c<='Z');
            
            if(i==0) {
                if(is_lower_case) {
                    shouldAllLowerCase = true;
                    isFirstUpperCase = false; 
                } else {
                    shouldAllLowerCase = false;
                    isFirstUpperCase = true;
                }
            } else if(i==1){
                if(shouldAllLowerCase) {
                    if(is_upper_case) return false;
                }
                if(isFirstUpperCase) {
                    shouldAllUpperCase = is_upper_case;
                }
            } else {
                if(shouldAllLowerCase) {
                    if(is_upper_case) return false;
                }
                if(shouldAllUpperCase) {
                    if(is_lower_case) return false;
                } else {
                    if(is_upper_case) return false;
                }           
            }
            i++;
        }
        return true;
    }
};