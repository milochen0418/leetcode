class Solution {
    //https://leetcode.com/problems/remove-digit-from-number-to-maximize-result
    //Article: https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/discuss/1998434/C%2B%2B-or-TC%3AO(N)-SC%3AO(1)-or-no-string-compare-or-explanation
    //FB Post: https://www.facebook.com/groups/1451299754892511/posts/5281480115207770/
public:
    string removeDigit(string number, char digit) {
        int pos = -1, n = number.size();
        for(int i = n-1; i>=0;i--) {
            if((number[i] == digit) && (pos == -1 || number[i+1]>number[i])) {
                pos = i;
            }
        }
        return number.erase(pos,1);
    }

    string removeDigit_v02(string number, char digit) {
        //weak new code from account milochen
        /*
        "0123"
        "01231"
        */
        //find out the first the largest digit that its rigit digit is greater than itself.
        int removeIdx = -1;
        int n = number.length();
        number.push_back('9'+1);
        for(int i = 0; i<n;i++) {
            if(number[i] == digit) {
                removeIdx = i;
                if(number[i+1]>number[i]) {
                    break;
                }
            }
        }
        //printf("removeIdx = %d\n",removeIdx);
        number.pop_back();
        return number.substr(0,removeIdx)+number.substr(removeIdx+1);
    }

};