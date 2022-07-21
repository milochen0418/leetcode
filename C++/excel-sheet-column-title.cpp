class Solution {
    //https://leetcode.com/problems/excel-sheet-column-title/
public:
    /*
        Observation
         A -> 1
         Z -> 26
        AA -> 26+1
        AB -> 26+2
        AZ -> 26+26
        BA -> 2*26+1
        ZA -> 26*26+1
        ZZ -> 26*26+26 -> like Z*26^1 + Z*26^0 
       AAA -> 26*26 + 26 + 1 
       ABA -> 26*26 + 2*26+1
       AZZ -> 26*26 + 26*26 + 26 -> like A*26^2 + Z*26^1 + Z*26^0
       BAA -> 2*26*26 +26 + 1   --> like B*26^2 + A*26^1 + A*26^0
       
       BA A-> 26*(B*26 + A) + A = B*26^2 + A*26 + A
       So, BA A = 26*(BA) + A
       if n%26 > 0, then sequence = 26*(n/26) + n%26
       if n%26== 0, then 先加1作計算，再回減1? (Just idea)
       
    */
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};