class Solution {
    //https://leetcode.com/problems/valid-palindrome-ii
    //article https://leetcode.com/problems/valid-palindrome-ii/discuss/1906369/C%2B%2B-or-two-pointer-or-explanation
public:
    bool validPalindrome(string s) {
        int L=0,R = s.length()-1;
        while(L<R) {
            if(s[R]!=s[L]) {
                int L1=L+1, R1=R;
                int L2=L,R2=R-1;
                bool case1=true, case2=true;
                while(L1<R1){
                    if(s[R1]!=s[L1]) {
                        case1=false;
                        break;
                    }
                    R1--;L1++;
                }
                while(L2<R2){
                    if(s[R2]!=s[L2]) {
                        case2=false;
                        break;
                    }
                    R2--;L2++;
                }
                return case1||case2;
            }            
            R--;L++;
        }
        return true;
    }

    bool answer2(string s) {
        int L=0,R = s.length()-1;
        while(L<R) {
            if(s[R--]!=s[L++]) {
                int L1=L, R1=R+1;
                int L2=L-1,R2=R;
                bool case1=true, case2=true;
                while(L1<R1){
                    if(s[R1--]==s[L1++]) continue;
                    case1=false;
                    break;
                }
                while(L2<R2){
                    if(s[R2--]==s[L2++]) continue;
                    case2=false;
                    break;
                }
                return case1||case2;
            }            
        }
        return true;
    }
};